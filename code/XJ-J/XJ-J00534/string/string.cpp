#include<bits/stdc++.h>
using namespace std;

long long chge=0,n;
struct node{
	int numb;
	char ci;
}p[200020];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].numb>>p[i].ci;
	}int l=0,r=n-1;
	long long ls=0,rs=0;
	while(l<=r){
		if(l==r){
			if(ls+rs<=p[l].numb){
				break;
			}
		}if(l+1==r&&((ls==0&&rs==p[r].numb-1)||(rs==0&&ls==p[l].numb-1))) break;
		if(l+2==r&&((ls==0&&rs==p[r].numb-2)||(rs==0&&ls==p[l].numb-2))) break;
		if(ls>0){
			if(ls>=p[r].numb){
				if(p[l].ci!=p[r].ci)chge+=p[r].numb;
				ls-=p[r].numb;
				r--;
			}else{
				if(p[l].ci!=p[r].ci)chge+=ls;
				rs=p[r].numb-ls;
				ls=0;
			}
		}if(rs>0){
			if(rs>=p[l].numb){
				if(p[l].ci!=p[r].ci)chge+=p[l].numb;
				rs-=p[l].numb;
				l++;
			}else{
				if(p[l].ci!=p[r].ci)chge+=rs;
				ls=p[l].numb-rs;
				ls=0;
			}
		}if(ls==0&&rs==0){
			if(p[l].numb>p[r].numb){
				if(p[l].ci!=p[r].ci)chge+=p[r].numb;
				ls=p[l].numb-p[r].numb;
				l++;
			}if(p[l].numb<p[r].numb){
				if(p[l].ci!=p[r].ci)chge+=p[l].numb;
				rs=p[r].numb-p[l].numb;
				r--;
			}if(p[l].numb==p[r].numb){
				if(p[l].ci!=p[r].ci)chge+=p[l].numb;
				l++,r--;
			}
		}
	}cout<<chge;
	return 0;
}
