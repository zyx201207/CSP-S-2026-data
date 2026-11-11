#include<bits/stdc++.h>
using namespace std;
struct zh{
	int anum;
	char ch;	
};
zh li[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long num,numz=0,ans=0;;
	cin>>num;
	for(int i=0;i<num;i++){
		char ch1;int num1;
		cin>>num1>>ch1;
		numz+=num1;
		li[i].anum=num1;li[i].ch=ch1;
	}
	//le=0,ri=numz-1
	long long gzl=0,gzr=num-1;
	while(gzl<=gzr){
		//le>=numz || ri<=0 ||
		if( gzl>=num || gzr<=0) break;
		if(li[gzl].ch==li[gzr].ch){
		//	le+=min(li[gzl].anum,li[gzr].anum);
		//	ri-=min(li[gzl].anum,li[gzr].anum);
			
			if(li[gzl].anum<li[gzr].anum){
				li[gzr].anum-=li[gzl].anum;
				gzl++;
			}else if(li[gzl].anum>li[gzr].anum){
				li[gzl].anum-=li[gzr].anum;
				gzr--;
			}else{
				gzl++; gzr--;
			}
			
		}else{
			ans+=min(li[gzl].anum,li[gzr].anum);
			
		//	cout<<ans<<" "<<gzl<<" "<<gzr<<endl;
			
			if(li[gzl].anum<li[gzr].anum){
				li[gzr].anum-=li[gzl].anum;
				gzl++;
			}else if(li[gzl].anum>li[gzr].anum){
				li[gzl].anum-=li[gzr].anum;
				gzr--;
			}else{
				gzl++; gzr--;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
//65 A   70  F 11
