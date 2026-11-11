#include<bits/stdc++.h>
using namespace std;
/*
¿¼Éú£ººúÔÅêÉ
¿¼ºÅ£ºSN-J00832
¿¼³¡´úÂë£º¹¤´óA2 
*/
int n,m,sum,num,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>c;
		for(int j=sum;j<sum+m;j++){
			s[j]=c;
		}
		sum+=m;
	}
	int xiabiao=sum-1;
	if(sum%2==1){
		num=xiabiao/2-1;
		for(int j=xiabiao/2+1;j<=xiabiao;j++){
			if(s[j]==s[num]){
				num--;
				continue;
			}
			else{
				ans+=1;
				num--;
			}
		}
	}
	else if(sum%2==0){
		num=xiabiao/2;
		for(int z=xiabiao/2+1;z<=xiabiao;z++){
			if(s[z]==s[num]){
				num--;
				continue;
			}
			else{
				ans+=1;
				num--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
