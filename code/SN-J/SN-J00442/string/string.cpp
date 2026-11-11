#include<bits/stdc++.h>
using namespace std;
long long n,pos,c[200005];
char s[200005];
long long ji,ji1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>s[i];
		ji+=c[i];
	}
	for(int i=1;i<=n;i++){
		ji1+=c[i];	
		if(ji1>=ji/2){
			pos=i;
			break;
		}

	}
	int i=1,j=n;
	while(i<=pos&&j>=pos){
		if(s[i]!=s[j])
			ans+=min(c[i],c[j]);
			if(c[i]>c[j]){
				c[i]-=c[j];
				j--;
				continue;
			}
			if(c[i]==c[j]){
				i++,j--;
				continue;
			}
			if(c[i]<c[j]){
				c[j]-=c[i];
				i++;
				continue;
			}
	}
	cout<<ans;
}



