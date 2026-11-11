#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack<int> s;
int apr[300050];
int est[300050];
int a[500050]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(apr[a[j]]==1){
				while(s.empty()==0 && s.top()!=a[j]){
					apr[s.top()]=0;
					//cout<<s.top()<<" ";
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				apr[a[j]]=1;
			}
		}
		//cout<<endl;
		while(s.empty()==0){
			//cout<<s.top()<<" ";
			apr[s.top()]=0;
			est[s.top()]++;
			s.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<est[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
