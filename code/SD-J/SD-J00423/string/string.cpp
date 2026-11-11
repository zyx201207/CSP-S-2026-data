#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	int cnt=0;
	string ss;
	int maxx=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>s[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			ss+=s[i];
		}
	}
	int f=0;
	for(int i=2;i<=n;i++){
		if(s[i]!=s[i-1]){
			f=1;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}   
	else if(sum%2==0){
		int l=0,r=sum-1;
		for(int i=1;i<=sum/2;i++){
			if(ss[l]-'a'!=ss[r]-'a')  cnt++;
			l++,r--;
		}	
	    printf("%d",cnt);
	}
	else if(maxx>=sum/2){
		cnt=sum-maxx;
	    printf("%d",cnt);
	}

	return 0;
} 
