#include<bits/stdc++.h>
#define intl long long
using namespace std;
const intl MAXn=100005;
char crr[MAXn]={0};
bool v=true;
intl n,ans=0,rew=0,al=1;
char wer;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
for(intl i=1;i<=n;i++){
	scanf("%lld %c",&rew,&wer);
for(intl q=al;q<=(al+rew);q++){
		crr[q]=wer;
	}
	al+=rew;
	}
	for(intl i=1;i<=al;i++){
if(crr[i]==crr[n-i]){
	v=true;
}
else{
	v=false;
	break;
}
}
ans=al;
if(v==true){
	printf("0");
}else{
for(intl i=1;i<=(al)/2;i++){
if(crr[i]==crr[al-i]){
	ans-=2;
}else{
	ans--;
}
}
printf("%lld",ans);
}
return 0;
}
