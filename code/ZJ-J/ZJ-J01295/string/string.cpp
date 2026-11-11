#include<bits/stdc++.h>
using namespace std;
struct p{
	int num;
	string c;
};
int n;
p a[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i].num,&a[i].c);
	}
	string temp=a[1].c,temp1=a[n].c;
	int x=a[1].num,y=a[n].num;
	for(int i=1,j=n;i<j;){
		if(x>=y){
			if(temp!=temp1){
				ans+=y;
			}	
			j--;
			x-=y;
			y=a[j].num;
			temp1=a[j].c;
		}
		else{
			if(temp!=temp1){
				ans+=x;
			}
			i++;
			y-=x;
			x=a[i].num;
			temp=a[i].c;
		}
	}
	cout<<ans;
}
