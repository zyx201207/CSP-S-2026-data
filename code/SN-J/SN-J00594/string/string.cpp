#include<bits/stdc++.h>
#define LL long long
using namespace std;
char s[1000000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	LL n,m;
	cin>>n;
	LL j=0;
	char ch;
	for(LL i=1;i<=n;i++){
		cin>>m>>ch;
		for(LL q=1;q<=m;q++){
			s[j]=ch;
			j++;
		}
	}
	/*for(int p=0;p<j;p++){
		cout<<s[p];
	}*/
	LL z=j-1;
	LL ans=0; 
	if(j%2==0){
		for(LL i=0;i<j;i++){
			if(i>j/2||z<j/2+1)break;
			if(s[i]!=s[z])ans++;
			z--;
		}
	}
	else{
		LL ret=j/2;
		for(int i=0;i<j;i++){
			//cout<<s[i]<<"sl99"<<s[z]<<endl; 
			if(z==ret||i==ret)break;
			else{
				if(s[i]!=s[z]){
					//cout<<i<<" "<<z<<endl;
					ans++;
				}
				/*if(s[i]==s[z]){
					cout<<i<<"99"<<z<<endl;
				}*/
				z--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
