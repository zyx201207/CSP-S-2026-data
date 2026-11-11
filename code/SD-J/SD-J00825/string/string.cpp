#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N];
char c[N];
int n;
long long ans,suma;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		suma+=a[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]){
			s+=c[i];
			a[i]--;
		}
	}
	for(long long i=0,j=suma-1;i<=(suma-1)/2;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	
	cout<<ans;
//	int cnt=1;
//	for(int i=1;i<=n;i++){
//		if(suma>=a[i]){
//			suma-=a[i];
//			cnt++;
//		}
//		else{
//			break;
//		}
//	}
//	int i=1,j=n;
//	while(i<=cnt){
//		if(c[i]==c[j]){
//			if(a[i]>a[j]){
//				a[i]-=a[j];
//				j--;
//			}
//			if(a[i]<a[j]){
//				a[j]-=a[i];
//				i++;
//			}
//			if(a[i]==a[j]){
//				i++;
//				j++;
//			}
//		}
//		if(c[i]!=c[j]){
//			if(a[i]>a[j]){
//				ans+=a[j];
//				a[i]-=a[j];
//				j--;
//			}
//			if(a[i]<a[j]){
//				ans+=a[i];
//				a[j]-=a[i];
//				i++;
//			}
//			if(a[i]==a[j]){
//				ans+=a[i];
//				i++;
//				j++;
//			}
//		}
//	}
	
	return 0;
}
