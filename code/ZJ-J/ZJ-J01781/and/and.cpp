#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],mx,s,mxx;
int cf(int x){
	int sum=2;
	for(int i=2;i<=x;i++){
		sum*=2;
	}
	return sum;
}
int an(int x,int y){
	int sum=0;
	int w=0;
	while(x>0&&y>0){
		int k=x%2;
		int l=y%2;
		if(l==k&&l==1){
			sum+=cf(w);
		}
		x/=2;
		y/=2;
		w++;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
	}else if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++){
			s=an(s,a[i]);
		}
		cout<<s;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			if(i==1){
				s=a[2];
				for(int j=3;j<=n;j++){
					s=an(s,a[j]);
				}
				mxx=max(mxx,s);
			}else{
				s=a[1];
				for(int j=2;j<=n;j++){
					if(j!=i){
						s=an(s,a[j]);
					}
				}
				mxx=max(mxx,s);
			}
		}
		cout<<mxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					s=an(a[i],a[j]);
					mxx=max(mxx,s);
				}
			}
		}
		cout<<mxx;
	}
	return 0;
}