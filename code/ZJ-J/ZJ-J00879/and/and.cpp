#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],b[N];
bool cmp(int x,int y){
	return x>y;
}
int s,w;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		int p;
		cin>>p;
		for(int i=2;i<=n;i++){
			int o;
			cin>>o;
			p=p&o;
		}
		cout<<p;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=30;i>=0;i--){
		w=0;
		bool f=false;
		int k=pow(2,i);
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]/k==1){
				b[++w]=a[j];
				cnt++;
				a[j]=a[j]%k;
			}
			if(cnt>=m){
				f=true;
				break;
			}
		}
		if(f){
			s=b[1];
			for(int j=1;j<=w;j++){
				s=s&b[j];
			}
			break;
		}
	}
	cout<<s;
	return 0;
} 
