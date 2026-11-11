#include<bits/stdc++.h>
using namespace std;
struct {long long a=0,sf=0;char c;} n[233333];//###THE FIRST BLOCK's INDEX START FROM 1!!!
struct p{int bi;long long ri;} lp,rp;//##block index & real index
int fd[233333];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    long long t=0;
    cin>>a;
    cin>>n[0].a>>n[0].c;
    n[0].sf=0;
    if(a==1) cout<<0;
    else{
    	for(int i=1;i<a;i++){
    	    cin>>n[i].a>>n[i].c;
    	    n[i].sf=n[i-1].sf+n[i-1].a;
    	}
    	n[a].sf=n[a-1].sf+n[a-1].a;
    	//cout<<n[a].sf<<' ';
    	if(n[a].sf%2){
    	    lp.ri=(n[a].sf-1)/2;
    	    rp.ri=(n[a].sf+3)/2;
    	    for(int i=0;i<a;i++){
    	    	if(n[i].sf+1<=lp.ri && lp.ri<=n[i].sf+n[i].a){
    	    	    lp.bi=i;
    	    	    break;
    	    	}
    	    }
    	    for(int i=lp.bi;i<a;i++){
    	    	if(n[i].sf+1<=rp.ri && rp.ri<=n[i].sf+n[i].a){
    	    	    rp.bi=i;
    	    	    break;
    	    	}
    	    }
    	}
    	else{
    	    lp.ri=n[a].sf/2;
    	    rp.ri=lp.ri+1;
    	    for(int i=0;i<a;i++){
    	    	if(n[i].sf+1<=lp.ri && lp.ri<=n[i].sf+n[i].a){
    	    	    lp.bi=i;
    	    	    break;
    	    	}
    	    }
    	    for(int i=lp.bi;i<a;i++){
    	    	if(n[i].sf+1<=rp.ri && rp.ri<=n[i].sf+n[i].a){
    	    	    rp.bi=i;
    	    	    break;
    	    	}
    	    }
    	}
    	//cout<<lp.ri<<' '<<lp.bi<<' '<<rp.ri<<' '<<rp.bi;
    	while(lp.bi>=0 && rp.bi<a){
    	    //cout<<lp.ri<<' '<<lp.bi<<','<<rp.ri<<' '<<rp.bi<<"  "<<n[lp.bi].sf<<','<<n[rp.bi+1].sf+1;
    	    if(lp.ri-n[lp.bi].sf<n[rp.bi+1].sf+1-rp.ri){
    	    	if(n[lp.bi].c!=n[rp.bi].c) t+=lp.ri-n[lp.bi].sf;
    	    	rp.ri+=lp.ri-n[lp.bi].sf;
    	    	lp.ri=n[lp.bi].sf;
    	    	lp.bi--;
    	    }
    	    else if(lp.ri-n[lp.bi].sf>n[rp.bi+1].sf+1-rp.ri){
    	    	if(n[lp.bi].c!=n[rp.bi].c) t+=n[rp.bi+1].sf+1-rp.ri;
    	    	lp.ri-=n[rp.bi+1].sf+1-rp.ri;
    	    	rp.bi++;
    	    	rp.ri=n[rp.bi].sf+1;
    	    }
    	    else{
    	    	if(n[lp.bi].c!=n[rp.bi].c) t+=lp.ri-n[lp.bi].sf;
    	    	lp.ri=n[lp.bi].sf;
    	    	lp.bi--;
    	    	rp.bi++;
    	    	rp.ri=n[rp.bi].sf+1;
    	    }
    	    //cout<<" ##"<<t<<endl;
    	}
    	cout<<t;
    }
    return 0;
}
