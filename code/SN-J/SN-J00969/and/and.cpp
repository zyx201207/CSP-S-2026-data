#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx=-100;
char w[200005],p[200005];
int xx=-100;
void fun(int x){
	char w[200005];
	int o=0,q=x;
	while(q!=0){
		q/=2;
		o++;
	}
	xx=max(xx,o);
	while(x!=0){
		w[o]=x%2;
		o--;
		x/=2;
	}
}
void fon(int x){
	int o=0,q=x;
	while(q!=0){
		q/=2;
		o++;
	}
	xx=max(xx,o);
	while(x!=0){
		p[o]=x%2;
		o--;
		x/=2;
	}
}
int er(int s,int cnt){
	bool bz=false;
	for(int i=xx;i>=1;i--){
		if(w[i]=='1'&&p[i]=='1'){
			bz=true;
			break;
		}
	}
	if(bz==false){
		return 0;
	}
	for(int i=xx;i>=1;i--){
		s=s+pow(cnt,2);
		cnt++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				fun(a[i]);
				fon(a[j]);
				mx=max(mx,er(0,0));
			}
		}
	}
	cout<<mx;
	return 0;
}

