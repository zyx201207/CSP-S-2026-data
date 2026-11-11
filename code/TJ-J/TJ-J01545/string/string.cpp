#include<bits/stdc++.h>
using namespace std;
long long a1[200005];
char a2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long sum=0;
	for(long long i=1;i<=n;i++){
		cin>>a1[i];
		sum+=a1[i];
		cin>>a2[i];
	}
	int s=1,l=n;
	int ans=0;
	for(int i=1;i<=(sum-1)/2+1;i++){
		if(a1[s]==0){
			s++;
		}
		if(a1[l]==0){
			l--;
		}
		if(a2[s]!=a2[l]){
			ans++;
			a1[s]--;
			a1[l]--;
		}
		else{
			a1[s]--;
			a1[l]--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
