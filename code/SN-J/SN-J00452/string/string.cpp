#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
string b[100005];
int endwe=0,frontwe=0;
long long ans;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];	
	}
	
	endwe+=n;
	frontwe+=1;
	while(frontwe!=endwe){
		if(b[frontwe]!=b[endwe]){
			ans+=min(a[frontwe],a[endwe])+1;
			
			if(a[frontwe]<a[endwe]){
				a[endwe]-=a[frontwe];
				frontwe--;
			
			}
			else if(a[frontwe]>a[endwe]){
				a[frontwe]-=a[endwe];
				endwe--;
			}
			else{
				frontwe--;
				endwe--;
			}
			
		}
		else{
			
			if(a[frontwe]>a[endwe]){
				a[frontwe]-=a[endwe];
				endwe--;
			}
			else if(a[frontwe]<a[endwe]){
				a[endwe]-=a[frontwe];
				frontwe--;
			}
			else{
				frontwe--;
				endwe--;
			}
		}
	}cout<<ans;
	return 0;
}
