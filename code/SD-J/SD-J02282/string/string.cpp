#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	struct s{
		int num;
		char q;
	}a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].q;
	}
	char s[1000000];
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			s[t]=a[i].q;
			t++;
		}
	}
	t--;
	int w=0;
	if(t%2==0){
		for(int i=1;i<=t/2-1;i++){
			for(int j=t;j>=t/2+1;j--){
				if(s[i]!=s[j]){
					s[j]=s[i];
					w++;
				}
			}
		}
	}
	else{
		for(int i=1;i<=t/2;i++){
			for(int j=t;j>=t/2;j--){
				if(s[i]!=s[j]){
					s[j]=s[i];
					w++;
					
				}
			}
		}
	}
	cout<<w;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
