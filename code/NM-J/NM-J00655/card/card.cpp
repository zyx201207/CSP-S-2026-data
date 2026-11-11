#include<bits/stdc++.h>
using namespace std;
long long a,b,ans1=0,ans2=0;
int c[100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	if(b==1){
		cout<<a;
	}else if(b==2){
		for(int i=0;i<a;i++){
			if(c[i]!=c[a-1]){
				ans1++;
				ans2++;
			}else if(c[i]==1){
				ans1++;
			}else if(c[i]==2){
				ans2++;
			}
		}
		cout<<ans1<<" "<<ans2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
