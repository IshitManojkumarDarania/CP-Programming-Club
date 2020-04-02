#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> zal(string s)
{
int n = s.size();
vector<int> z(n);
int x = 0, y = 0;
for (int i = 1; i < n; i++) {
z[i] = max(0,min(z[i-x],y-i+1));
while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
x = i; y = i+z[i]; z[i]++;
}
}
return z;
}
string fps(string s){
    const int m = s.length();
    if(m<2)
        return s;
    string s2 = "#";
    for(int i = 0; i < m; i++)
        s2.push_back(s[i]), s2.push_back('#');

    int cx = 0, mx = 0;
    const int m2 = 2*m+1;
    vector<int> dp(m2,0);

    for(int i = 1; i < m2; i++){
        int j = 0;
        if(i>=mx)
            j = i+1;
        else{
            int ii = 2*cx-i;
            dp[i] = min(mx-i,dp[ii]);
            if(ii-dp[ii]<=cx-dp[cx])
                j = mx+1;
        }

        while(j&&(j<m2)&&(2*i-j>=0)&&(s2[j]==s2[2*i-j]))
            dp[i]++, j++;

        if(i+dp[i]>mx)
            mx = i+dp[i], cx = i;
    }

    int mxl = 0;
    int id = 0;
    for(int i = 1; i < m2; i++)
        if(dp[i]>mxl){
            mxl = dp[i];
            id = i;
        }

    string res;
    for(int j = id-dp[id]+1; j <= id+dp[id]; j+=2)
        res.push_back(s2[j]);

    return res;
}
int main()
{
    ll i,j,k,n;
    string s,s1;
    cin>>s;
    cin>>s1;
    k=s1.size();
    s1.push_back('#');
    s1.append(s);
    vector<int>ans=zal(s1);
    sort(ans.begin(),ans.end());
    ll coun=0;
    for(auto x:ans)
    {
        if(x==k)
        {
            coun++;
        }
    }
    string pal=fps(s);
    cout<<pal<<endl;
    cout<<coun<<endl;
    return 0;
}
