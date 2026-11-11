#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
    cin>>n>>m;
    stack<int> a;
    int s[n];
    int r[m]={0};
    int p[m]={0};
    for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(p[s[j]-1]==1){
			   while(a.top()==s[j]){
				   p[a.top()-1]=0;
				   a.pop();
			}
		}
		else{
			a.push(s[j]);
			p[s[j]-1]=1;
		    }
	   }
	   while(!a.empty()){
			r[a.top()-1]++;
			a.pop();
		}
    }
    for(int i=0;i<m;i++){
		cout<<r[i]<<" ";
	}
    return 0;
}
