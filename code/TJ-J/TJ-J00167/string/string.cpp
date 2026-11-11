#include<bits/stdc++.h>
using namespace std;
int n,a,num=0;
char c,ans[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		ans[i]+=c;
		ans[i]++;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]!=ans[i+1]){
			ans[i+1]=ans[i];
			ans[i++];
			num++;
		}else{
			num+=0;
		}
	}
	cout<<num;
	return 0;
} 
