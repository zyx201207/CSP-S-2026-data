#include<bits/stdc++.h>
using namespace std;

string s;
long long t,n[200001],len,ans;
char x[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>t;
	for(long long i=1;i<=t;i++) cin>>n[i]>>x[i];
	int i=1,j=t;
	while(i<j){
		if(x[i]==x[j]){
			int minn=min(n[i],n[j]);
			n[i]-=minn,n[j]-=minn;
			if(n[i]==0) i++;
			if(n[j]==0) j--;
		}else if(x[i]!=x[j]){
			int minn=min(n[i],n[j]);
			ans+=minn;
			n[i]-=minn,n[j]-=minn;
			if(n[i]==0) i++;
			if(n[j]==0) j--;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}

