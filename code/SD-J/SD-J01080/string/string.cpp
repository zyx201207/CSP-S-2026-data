#include<bits/stdc++.h>
using namespace std;
struct ljl{
	long long num;
	char a;
};
ljl x[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int dui=n;
	for(int ii=1;ii<=n;ii++)cin>>x[ii].num>>x[ii].a;
	int i=1;
	while(i<dui){
		if(i+1==dui&&x[dui].num%2!=0){
			x[dui].num-=1;
			if(x[dui].num==0)break;
		}
		if(x[dui].a==x[i].a){
			if(x[i].num>x[dui].num){
				x[i].num-=x[dui].num;dui-=1;
			}else if(x[i].num<x[dui].num){
			    //cout<<x[i].num<<" "<<x[dui].num<<endl;
			    x[dui].num-=x[i].num;i++;
			}else{
				i++;dui-=1;
			}
			//cout<<dui<<endl;
		}else{	
			if(x[i].num>x[dui].num){
				x[i].num-=x[dui].num;
				ans+=x[dui].num;
				dui-=1;
			}else if(x[i].num<x[dui].num){
				x[dui].num-=x[i].num;
				ans+=x[i].num;
				i++;
			}else{
				ans+=x[i].num;
				i++;
				dui--;
			}
			//cout<<dui<<endl;
		}
	}cout<<ans;
	return 0;
} 
