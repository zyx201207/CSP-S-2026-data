#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	int num[N];
	char ch[N];
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>ch[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(l==r)break;
		int mn=min(num[l],num[r]);
		if(ch[l]!=ch[r])ans+=mn;
		num[l]-=mn,num[r]-=mn;
		if(num[l]==0)l++;
		if(num[r]==0)r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
