 #include<bits/stdc++.h>
 using namespace std;
 string s;
 int main(){
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	int n,a,ans=0;
 	char c;
 	scanf("%d",&n);
 	for(int i=1;i<=n;i++){
 		cin>>a>>c;
 		for(int j=0;j<a;j++){
 			s+=c;
		}
	}
	if(s.length()==1){
		printf("0");
		return 0;
	}
	for(int i=0;i<=s.length()/2-1;i++){
		if(s[1]!=s[s.length()-i-1])ans++;
	}
	printf("%d",ans);
 	return 0;
 }
