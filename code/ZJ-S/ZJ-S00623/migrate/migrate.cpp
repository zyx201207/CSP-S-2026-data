#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
//10pts
int c,t;
int a[N];
//void bl(){
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			if(a[j]-a[i]>d&&a[j]-a[i]<2*d&&a[j-1]-a[i]<=d){
//				cnt++;
//			}
//		}
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		c=a[2]-a[1];
		if(d>=abs(a[n]-a[1])){
			cout<<0;
			continue;
		}
		bool f=1,fl=1;
		for(int i=1;i<n;i++){
			if(abs(a[i+1]-a[i])!=c){
				f=0;
				continue;
			}
		}
		int len=n;
		if(f){
			if(d<=2*c){
				for(int i=1;i<=len;i++){
					for(int j=i;j<=len;j++){
						if((j-i)*c==d+c){
							cnt++;
						}
					}
				}
			}
		}
		else{
			for(int i=1;i<=len;i++){
				for(int j=i;j<=len;j++){
					if(j-i>=3&&abs(a[j]-a[i])>d&&abs(a[j]-a[i])<2*d&&a[j-1]-a[i]<=d){

						cnt++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
