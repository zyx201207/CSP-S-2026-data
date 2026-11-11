#include<bits/stdc++.h> 
using namespace std;
struct q{
	long long a;
	char c;
}k[200005];
q kk[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i].a>>k[i].c;
		kk[i]=k[i];
	}
	long long sum1=0,sum2=0;
	int l=n,f=1;
	while(l>=f){
		long long w=kk[f].a;
		while(w>0&&l>n/2){
			if(kk[l].c!=kk[f].c){
	   		if(w>=kk[l].a){
	   			w-=kk[l].a;
	   			sum1+=kk[l].a;
	   			l--;
			   }else{
			   	kk[l].a-=w;
			   	sum1+=w;
			   	w=0;
			   }
		   }else{
		   	if(w>=kk[l].a){
	   			w-=kk[l].a;
	   			l--;
			   }else{
			   	kk[l].a-=w;
			   	w=0;
			   }
		   }
		}
		f++;
	}
	for(int i=1;i<=n;i++){
		kk[i]=k[i];
	}
	l=n;
	f=1;	
	while(f<=l){
		long long w=kk[l].a;
		while(w>0&&l>n/2){
			if(kk[l].c!=kk[f].c){
	   		if(w>=kk[f].a){
	   			w-=kk[f].a;
	   			sum2+=kk[f].a;
	   			f++;
			   }else{
			   	kk[f].a-=w;
			   	sum2+=w;
			   	w=0;
			   }
		   }else{
		   	if(w>=kk[f].a){
	   			w-=kk[f].a;
	   			f++;
			   }else{
			   	kk[f].a-=w;
			   	w=0;
			   }
		   }
		}
		l--;
	}
	if(sum1<sum2)cout<<sum1;
	else cout<<sum2;
	return 0;
}
