#include<bits/stdc++.h>
using namespace std;
long long N1[5000000];
long long N2[5000000];
long long S1[5000000];
long long S2[5000000];
char c1[5000000];
char c2[5000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,L=0,ans=0,k=1,d1=1,d2=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>N1[i]>>c1[i];
		N2[n+1-i]=N1[i];
		c2[n+1-i]=c1[i];
	} 
	for(int i=1;i<=n;i++){
		S1[i]=S1[i-1]+N1[i];
		S2[i]=S2[i-1]+N2[i];
	} 
	while(S1[d1]<=(S1[n]+1)/2||S2[d2]<=(S2[n]+1)/2){
		if(c1[d1]!=c2[d2]){
			if(N1[d1]<N2[d2]){
				ans+=N1[d1];
				N2[d2]-=N1[d1];
				d1++;
			}
			else if(N1[d1]>N2[d2]){
				ans+=N2[d2];
				N1[d1]-=N2[d2];
				d2++;
			}
			else if(N1[d1]==N2[d2]){
				ans+=N1[d1];
				d1++;
				d2++;
			}
		}
		else {
			if(N1[d1]<N2[d2]){
				N2[d2]-=N1[d1];
				d1++;
			}
			else if(N1[d1]>N2[d2]){
				N1[d1]-=N2[d2];
				d2++;
			}
			else {
				d1++;
				d2++;
			}
		}
	}
	cout<<ans;
	return 0;
}
