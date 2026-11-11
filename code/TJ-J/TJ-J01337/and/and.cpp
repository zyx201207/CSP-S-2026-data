#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000000],d,e,r,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	if(b==1){
		sort(c+1,c+a+1);
		cout<<c[a];
		return 0;
	}
	if(b==a){
		r=c[1];
		for(int i=2;i<=a;i++){
			r=(r&c[i]);
		}
		cout<<r;
		return 0;
	}
	if(b==2){
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a;j++){
				if(i==j) continue;
				r=(c[i]&c[j]);
				if(r>e) e=r;
			}
		}
		cout<<e;
		return 0;
	}
	if(b==a-1){
		for(int i=1;i<=a;i++){
			if(i==1){
				r=c[2];
				for(int j=3;j<=a;j++){
					r=(r&c[j]);
				}
				e=r;
			}
			else{
				r=c[1];
				for(int j=2;j<=a;j++){
					if(j!=i) r=(r&c[j]);
				}
				if(r>e) e=r;
			}
		}
		cout<<e;
		return 0;
	}
	return 0;
}
