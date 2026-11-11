//20261031-cspj-00547-t2
#include<bits/stdc++.h>
using namespace std;
struct part{
	char c;
	int s;
};
int main(){
	//不不不不不这无疑是困难的
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//不不不不不差点忘取消注释freopen了 
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	part p[100005];
	int n,cnt=0;
	cin>>n;
	for(int i =0;i<n;i++)
	{
		cin>>p[i].s>>p[i].c;
	}
	part lst;
	lst.c=0;lst.s=0;
	bool lsts = 0,lstb=0;
	for(int i=0;i<n/2;i++){
		//cout<<p[i].s<<p[i].c;
		//cout<<p[n-i-1].s<<p[n-i-1].c;
		if(lstb){
			if(lsts&&(lst.c==p[n-i-1].c)){
				if(lst.s > p[n-i-1].s){
					lstb=1;
					lsts=0;
					lst.s=lst.s-p[n-i-1].s;
				}
				if(lst.s < p[n-i-1].s){
					lstb=1;
					lsts=1;
					lst.s=p[n-i-1].s-lst.s;
				}else{
					
				}
			}else{
				cnt+=lst.s;
				lstb=0;
				lst.s=0;
				lsts=0;
			}
		}
		else if(p[i].c==p[n-i-1].c){
			if(p[i].s > p[n-i-1].s){
				lstb=1;
				lsts=0;
				lst.c=p[i].c;
				lst.s=p[i].s-p[n-i-1].s;
			}else if(p[i].s < p[i].s){
				lstb=1;
				lsts=1;
				lst.c=p[i].c;
				lst.s=p[n-i-1].s-p[i].s;
			}
		}else{
			cnt+=p[n-i-1].s;
		}
		
	}
	cout<<cnt;
	return 0;
}
