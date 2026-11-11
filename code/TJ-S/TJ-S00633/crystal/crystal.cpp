#include<bits/stdc++.h>
using namespace std;

int a[600000];
bool r=true;
bool t=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,q=0,g=0,p,ma=INT_MIN,cnt=0,h,k,l,v=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			r=false;
		}
	}p=abs(a[1]-a[2]);
	for(int i=2;i<=n;i++){
		if(abs(a[2]-a[1])!=p){
			t=false;
		}
	}
	if(r==true){
		for(int i=1;i<=n;i++){
			q+=a[i];
			if(q-a[i]>m){
				cout<<i-1;
				return 0;
			}
		}cout<<n;
		return 0;
	}else if(t==true){
		sort(a,a+n+1);
		g=a[2]-a[1];
		for(int i=1;i<=n;i++){
			q=0;
//			cout<<a[i];
			for(int j=0;j<i;j++){
				q+=j;
			}if(g*q>m){
				cout<<i-1;
				return 0;
			}
		}cout<<n;
		return 0;
//		if(a[1]>a[2]){
//			for(int i=1;i<=n;i++){
//				q+=2*i;
//				if(q>m){
//					cout<<i-1;
//					return 0;
//				}
//			}
//		}else if(a[1]<a[2]){
//			
//		}
	}else{
		sort(a,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]>=0){
				if(a[i]==a[i+1]){
					cnt++;
					h=a[i];
				}if(a[i]!=a[i+1]){
					if(cnt>=ma){
						ma=cnt;
						cnt=0;
						k=h;
					}
				}
			}
		}for(int i=1;i<=n;i++){
			if(a[i]==k){
				l=i;
				break;
			}
		}for(int i=l;i>=1;i--){
			if(m-(a[i]-a[i-1])>=0){
				ma+=1;
			}else if(m-(a[i]-a[i-1])<0){
				break;
			}
		}
	}for(int i=1;i<=n;i++){
		if(m<0){
			break;
		}
		m-=(a[n]-a[i]);
		c++;
		
	}if(ma>=c){
		cout<<ma;
	}else{
		cout<<c;
	}
	return 0;
}
