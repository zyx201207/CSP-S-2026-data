#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long maxx=-1000;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
//	cin>>n>>m;
	scanf("%d %d",&n,&m);
	long long x;
	if(m==1){
		for(int i=0;i<n;i++){
//			cin>>x;
			scanf("%lld",&x);
			maxx=max(maxx,x);
		}
//		cout<<maxx;
		printf("%d",maxx);
		return 0;
	}
	else if(m==n){
		cin>>x;
		maxx=x;
		for(int i=1;i<n;i++){
//			cin>>x;
			scanf("%lld",&x);
			maxx=maxx&x;
		}
//		cout<<maxx;
		printf("%d",maxx);
		return 0;
	}
	else if(m==2){
		long long t=0;
		for(int i=0;i<n;i++){
//			cin>>a[i];
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				t=0;
				t=a[i];
				t&=a[j];
				maxx=max(maxx,t);
			}
		}
//		cout<<maxx;
		printf("%d",maxx);
		return 0;
	}
	else{
		long long t=0;
		for(int i=0;i<n;i++){
//			cin>>a[i];
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m-1;j++){
				for(int z=i+1+j;z<n;z++){
					t=0;
					t=a[i];
					t&=a[z];
				}
			}
			maxx=max(maxx,t);
		}
//		cout<<maxx;
		printf("%d",maxx);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
