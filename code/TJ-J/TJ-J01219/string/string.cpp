#include<bits/stdc++.h>
using namespace std;
struct zifuchuanpinjie{
	long long a;
	char b;
}s[300001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	long long p1=0,p2=n-1,ans=0;
	while(1){
		if(s[p1].a==0){
			p1+=1;
		}
		if(s[p2].a==0){
			p2-=1;
		}
		int minas=min(s[p1].a,s[p2].a);
		if(s[p1].b==s[p2].b){
			s[p1].a-=minas;
			s[p2].a-=minas;
		}else{
			ans+=minas;
			s[p1].a=s[p1].a-minas;
			s[p2].a=s[p2].a-minas;
		}
		if((p2-p1==1||p2-p1==2)&&((s[p1].b==s[p2].b)||(s[p1].a==0&&s[p2].a==0))){
			break;
			
		}
		if(p2-p1<=0){
			break;
			
		}
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout);
	return 0;
}
