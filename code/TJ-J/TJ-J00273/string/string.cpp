#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct Node{
	long long num;
	char v;

}nrr[200055],check[200055];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nrr[i].num>>nrr[i].v;
		check[n-i+1].num=nrr[i].num;
		check[n-i+1].v=nrr[i].v;
	}
	int j=1;
	for(int i=1;i<=n;){
		if(check[j].v==nrr[i].v){
			if(check[j].num>nrr[i].num){
				check[j].num-=nrr[i].num;
				i++;
			}
			else if(check[j].num<nrr[i].num){
				nrr[i].num-=check[j].num;
				j++;
			}
			else if(check[j].num==nrr[i].num){
				i++;
				j++;
			}
			
		}
		else{
			if(check[j].num>nrr[i].num){
				check[j].num-=nrr[i].num;
				ans+=nrr[i].num;
				i++;
				
			}
			else if(check[j].num<nrr[i].num){
				nrr[i].num-=check[j].num;
				ans+=check[j].num;
				j++;
				
			}
			else if(check[j].num==nrr[i].num){
				ans+=nrr[i].num;
				i++;
				j++;
				
			}
			
		}
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
} 
