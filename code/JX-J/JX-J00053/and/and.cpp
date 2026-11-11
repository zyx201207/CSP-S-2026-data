#include <bits/stdc++.h>
#define LL long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n,m;
LL a[1000005];
string yx(LL a){
    string wz="";
    while(a){
        char d=48+a%2;
        wz=d+wz;
        a/=2;
    }
    return wz;
}
string zh(string a,string b){
    int lena=a.size();
    int lenb=b.size();
    if(lena>lenb){
        for(int i=0;i<lena-lenb;i++){
            b='0'+b;
        }
        lenb=lena;
    }else if(lenb>lena){
        for(int i=0;i<lenb-lena;i++){
            a='0'+a;
        }
        lena=lenb;
    }
    string yy="";
    int i=0;
    while(lena--){
        if(a[i]!=b[i]) yy+="0";
        else if(a[i]==b[i] && a[i]==49) yy+="1";
        i++;
    }
    return yy;
}
int yy(string a){
    int ans=0;
    for(int i=0;i<a.size();i++){
        ans+=pow(2,a.size()-i-1)*a[i];
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    IOS;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
    }
    if(m==2){
        string maxs="0000";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxs=min(maxs,zh(yx(a[i]),yx(a[j])));
            }
        }
        cout<<yy(maxs);
        return 0;
    }
    if(m==n-1){
        string maxs="";
        for(int i=0;i<n;i++){
            string d="";
            for(int j=0;j<n;j++){
                if(j==i) continue;
                d=zh(yx(a[j]),d);
            }
            maxs=min(d,maxs);
        }
        cout<<yy(maxs);
        return 0;
    }



    return 0;
}
