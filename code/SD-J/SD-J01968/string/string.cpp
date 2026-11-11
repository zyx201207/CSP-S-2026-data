#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,l=0,t;
long long cnt;
struct lname{
	int tl;
	char name;
}k[200005]; 
char ct;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>k[i].tl>>k[i].name;
	}
	int q=0;
	char q2=' ';
	int i=0,j=n+1;
	while(i<j){
		if(q>0){
			j--;
			if(q!=0){
				int t=abs(k[j].tl-q);
				if(q2!=' '&&q2!=k[j].name)
					cnt+=min(abs(q),k[j].tl);
			}
			q-=k[j].tl;
			if(q<0)
				q2=k[j].name;
		}
		else{
			i++;
			if(q!=0){
				int t=abs(k[i].tl-q);
				if(q2!=' '&&q2!=k[i].name){
					cout<000;
					cnt+=min(abs(q),k[i].tl);
				}
					
			}
			q+=k[i].tl;
			if(q>0)
				q2=k[i].name;
		}
	}
	if(n%1==0){
		if(q!=0){
			if(q2!=' '&&q2!=k[i].name)
				cnt+=min(abs(q),k[i].tl);
		}
	}
	cout<<cnt;
	return 0;
}
