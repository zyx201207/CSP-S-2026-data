#include<bits/stdc++.h>
using namespace std;
int annd(int a,int b){
    long long c=0,d=0,bs=1,s=0,ss=0,ls=a;
    while(a>0){
        c+=a%2*bs;
        a/=2;bs*=10;
    }
    bs=1;
    while(b>0){
        d+=b%2*bs;
        b/=2;bs*=10;
    }
    bs=1;
    if(c>d){
        while(d>0){
            if(c%10==1 && d%10==1){
                s=s+=bs;
            }
            bs*=10;c/=10;d/=10;
        }
        bs=0;
        while(s>0){
            ss+=s%10*pow(2,bs);
            s/=10;bs++;
        }
        return ss;
    }else if(c<d){
        while(c>0){
            if(c%10==1 && d%10==1){
                s=s+=bs;
            }
            bs*=10;c/=10;d/=10;
        }
        bs=0;
        while(s>0){
            ss+=s%10*pow(2,bs);
            s/=10;bs++;
        }
        return ss;
    }else{
        return ls;
    }
}
bool cmp(int a,int b){
    if(a>b){
        return true;
    }else{
        return false;
    }
}
int a[300005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,t;
	cin >> n >> m;
	for(i=1;i<=n;i++){
        cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	t=a[1];
	for(i=2;i<=m;i++){
        t=annd(t,a[i]);
	}
	cout << t;
	return 0;
}
