//孙瑞泽	SN-J00783	西安市第八十九中学 
#include<bits/stdc++.h>
using namespace std;
long long ans,len=0,s,num[200005],ls=0,rs,rl,lr,lel=0,rr;
char word[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	rs=s-1;
	for(int i=0;i<s;i++){
		cin>>num[i]>>word[i];
		len+=num[i];
	}
	rr=len-1;
	lr=num[0]-1;
	rl=len-num[s-1]-1;
	while (ls<=rs){
		if(num[ls]<num[rs]){
			if(word[ls]!=word[rs])
			ans+=num[ls];
			num[rs]-=num[ls];
			lel==lr;
			rr-=num[ls];
			ls++;
			lr+=num[ls];
			
		}else if(num[ls]==num[rs]){
			if(word[ls]!=word[rs])
			ans+=num[ls];
			lel=lr;
			rr=rl;
			ls++;
			rs--;
			lr+=num[ls];
			rl-=num[rs];
		}else{
			if(word[ls]!=word[rs])
			ans+=num[rs];
			num[ls]-=num[rs];
			rr=rl;
			lel+=num[rs];
			rs--;
			rl-=num[rs];
		}
	}
	cout<<ans;
}
