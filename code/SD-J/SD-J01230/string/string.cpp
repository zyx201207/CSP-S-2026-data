#include<bits/stdc++.h>
using namespace std;
string s; 
int n;
int a;
char c;
int check(string x){
	int ans=0; 
	char h=0,t=x.size()-1;
	while(h<=t){
		if(x[h]!=x[t]){
			ans++;
		}
		h++;
		t--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%c",&a,&c); 
		for(int j=1;j<=a;j++){
			s=s+c;
		}
	}
	printf("%d",check(s));
	return 0;
} 
