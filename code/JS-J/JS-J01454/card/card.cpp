#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct de{
	ll len,x[500005];
};
ll n,m,a[500005],ck[500005][500005];
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){f=-1;}
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	n=read();
	m=read();
	ll mx=-1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		mx=max(mx,a[i]);
	}
	for(int id=1;id<=n;id++){
		de desk;
		for(int i=id;i<=n;i++){
			for(int it=1;it<=desk.len;it++){
				if(desk.x[it]==a[i]){
					for(int j=it;j<=desk.len;j++){
						desk.x[j]=0;
					}
					desk.len-=desk.len-it+1;
				}
			}
			desk.x[desk.len+1]=a[i];
			desk.len++;
		}
		for(int i=1;i<=desk.len;i++){
			ck[desk.x[i]][id]++;
		}
	}
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=1;j<=n;j++){
			if(ck[a[n]][j]!=0){
				cnt++;
			}
		}
		cout<<cnt;
	}
    return 0;
}

