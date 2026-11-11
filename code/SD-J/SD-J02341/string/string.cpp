#include<bits/stdc++.h>
using namespace std;
long long l=1,r,ans=0,lcnt,rcnt,n;
int a[100005];
char c[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	r=n;
	lcnt=a[1];
	rcnt=a[n];
	while(l<=r){
		if(lcnt>rcnt){//左多 
			if(c[l]!=c[r])ans+=rcnt;//字母不同 计数 
			lcnt-=a[r];//左个数减少 
			r--;//位置左移 
			rcnt=a[r];//加新位置个数 
		}
		else if(lcnt<rcnt){//右多 
			if(c[l]!=c[r])ans+=lcnt;
			rcnt-=a[l];
			l++;
			lcnt=a[l];	
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			l++;
			r--;
			rcnt=a[r];
			lcnt=a[l];
		}
		//cout<<l<<r<<lcnt<<rcnt<<ans<<endl;
	}
	cout<<ans;
	return 0;
}

