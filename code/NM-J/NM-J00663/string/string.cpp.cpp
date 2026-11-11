#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0,s=1,e=n;
	while(s<e){
		if(a[s]==a[e]&&c[s]==c[e]){
			s++;
			e--;
		}
		else if(a[s]==a[e]&&c[s]!=c[e]){
			ans+=a[s];
			s++;
			e--;
		}
		else {
			if(a[s]>a[e]){
				while(a[s]>=a[e]&&s<e){
					if(c[s]==c[e]){
						a[s]-=a[e];
						e--;
					}
					else {
						ans+=a[e];
						a[s]-=a[e];
						e--;
					}
				}
				if(s==e) break;
				if(c[s]==c[e]){
					a[e]-=a[s];
				}
				else {
					a[e]-=a[s];
					ans+=a[s];
				}
				s++;
			}
			else if(a[s]<a[e]){
				while(a[s]<=a[e]&&s<e){
					if(c[s]==c[e]){
						a[e]-=a[s];
						s++;
					}
					else {
						a[e]-=a[s];
						ans+=a[s];
						s++;
					}
				}
				if(s==e) break;
				if(c[s]==c[e]){
					a[s]-=a[e];
				}
				else {
					a[s]-=a[e];
					ans+=a[e];
				}
				e--;
			}
		}
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout); 
	return 0;
}


