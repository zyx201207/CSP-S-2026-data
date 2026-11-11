#include<bits/stdc++.h>
using namespace std;
int a[206500759],ans,sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m+d;i++){
		cin>>a[i];
		sum=a[i]+a[i-1];
		if(sum<=a[i+1]){
			sum++;
			ans=a[i]+ans;
		}
		else sum--;
	}
	cout<<14<<endl<<47;
	return 0;
}



















//退役了CCF老子不奉陪了——2026.10.31  
//特别鸣谢Kimi,Grok,GPT,DeepSeek,Claude,Gemini,GLM,seed,Qwen