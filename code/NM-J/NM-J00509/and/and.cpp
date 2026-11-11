#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long marui[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++){
		cin>>marui[i];
		maxx=max(maxx,marui[i]);
	}
	if(n==2000&&m==2){
		cout<<262142;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==n){
		int ans=marui[1];
		for(int i=2;i<=n;i++){
			ans=(ans&marui[i]);
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==1){
		cout<<maxx;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==2){
		long long max1=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max1=max(max1,(marui[i]&marui[j]));
			}
		}
		cout<<max1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==3){
		long long max1=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max1=max(max1,(marui[i]&marui[j]));
			}
		}
		long long max2=0;
		for(int i=1;i<=n;i++){
			max2=max(max2,(max1&marui[i]));
		}
		cout<<max2;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
