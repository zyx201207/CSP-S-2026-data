#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s[200005];
    long long n,zifuzongshu=0;
    cin>>n;
    for (long long i=0;i<n;i++){
        long long count;
        cin>>count;
        char c;
        cin>>c;
        for (long long j=0;j<count;j++){
            s[zifuzongshu+j]=c;
        }
        zifuzongshu+=count;
    }
    string s1[zifuzongshu],s2[zifuzongshu];
    for (long long i=0;i<zifuzongshu;i++){
        s1[i]=s[i];
        s2[zifuzongshu-1-i]=s[i];
    }
    long long need=0;
    for (long long i=0;i<zifuzongshu/2;i++){
        if(s1[i]!=s2[i]){
            need+=1;
        }
    }
    cout<<need;
    return 0;
}
