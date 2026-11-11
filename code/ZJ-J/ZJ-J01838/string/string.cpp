#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<long long> a(n+1,0);
	vector<char> c(n+1,0);
	long long M=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		M+=a[i];
	}
	long long ans=0;
	M=M/2+(M%2);
	int j=n,i=1;
	while(true){
		if(c[j]!=c[i]){
			if(a[j]>a[i]){
				if(M-ans<a[i]){
					ans=M;
					break;
				}else{
					a[j]-=a[i];
					ans+=a[i];
					i++;
				}
			}else{
				if(M-ans<a[j]){
					ans=M;
					break;
				}else{
					a[i]-=a[j];
					ans+=a[j];
					j--;
				}
			}
		}else{
			if(i==j){
				break;
			}
			if(a[i]<a[j]){
				M-=a[i];
				a[j]-=a[i];
				i++;
			}else{
				M-=a[j];
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

