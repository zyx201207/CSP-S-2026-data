#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],t[N],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//rp++++++++++++++++++++++++++++++++++++++++++++++ 
	/*
	累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 累 
	第一次参加CSP：累 累 累 
	什么叫我第四题做出来了（不一定）但第三题不会？？
	！？弱弱？！
	！？区区？！ 
	先睡会
	 
	*/ 
	
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		stack<int> s;
        int mk[N]={};
		for(int i=k;i<=n;i++){
			if(mk[a[i]]==0){
				mk[a[i]]=1;
				s.push(a[i]);
			}else {
				while(s.top()!=a[i]){
					mk[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int o=0;o<=N;o++){
			mk[o]=0;
		}
		while(!s.empty()){
			if(!mk[s.top()]){
				mk[s.top()]=1;
				t[s.top()]++;
			}
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	return 0;
}
