#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	string N;
	cin>>a;
	while(a--){
		long long n;string m;
		cin>>n>>m;
		for(long long i=0;i<n;i++) N+=m;
	}
	string N1;long long N2=N.size(); 
	if(N2%2==1) N2++;
	for(long long i=0;i<N2/2-1;i++){
		N1+=N[i];
	}
	long long ans=0;
	int j=N1.size();
	for(int i=N2/2;i<=N.size()-1;i++){
		j--;
		if(N1[j]==N[i]) continue;
		ans++;
	}
	cout<<ans;
	fclose(stdin);fclose(stdout); 
	return 0;
} 
