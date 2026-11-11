#include<bits/stdc++.h>
using namespace std;

int n,m;

struct node{
    long long num;
    string s;
};

node a[200010];

void totwo(int i){
    long long sum=a[i].num;
    string ss="";
    while(sum!=0){
        ss=to_string(sum%2)+ss;
        sum=sum/2;
    }
    a[i].s=ss;
    return;
}

long long toten(string s){
    long long ans=0;
    for(int i=0;i<s.size();i++){
        long long t=1;
        for(int j=1;j<=i;j++){
            t*=2;
        }
        ans+=(s[i]-'0')*t;
    }
    return ans;
}

long long f(int i,int j){
    string aa=a[i].s,bb=a[j].s;
    int l;
    if(aa.size()>bb.size()){
        l=aa.size();
        for(int i=1;i<=aa.size()-bb.size();i++){
            bb="0"+bb;
        }
    }
    else{
        l=bb.size();
        for(int i=1;i<=bb.size()-aa.size();i++){
            aa="0"+aa;
        }
    }
    //cout << aa << " " << bb << endl;
    string ans="";
    for(int i=0;i<l;i++){
        if(aa[i]=='1'&&bb[i]=='1') ans=ans+"1";
        else if(aa[i]=='0'||bb[i]=='0') ans=ans+"0";
    }
    long long anss=toten(ans);
    return anss;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i].num;
        totwo(i);
    }
    if(m==1){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i].num);
        }
        cout << maxx;
    }
    if(m==2){
        long long maxx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //cout << i << " " << j << " " << f(i,j) << endl;
                maxx=max(maxx,f(i,j));
            }
        }
        cout << maxx;
    }
    return 0;
}
