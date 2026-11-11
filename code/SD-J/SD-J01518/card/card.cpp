#include<bits/stdc++.h>
using namespace std;
stack<int> a; 
int n,m,ans[300005],aa[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a.push(aa[j]);
			int key=1,ii=0;
			for(int k=i;k<=j-1;k++){
				if(aa[k]==aa[j]){
					key=0;
					ii=k;
					break;
				}
			}
			if(key==0){
				//cout<<endl;
				for(int k=ii;k<=j-1;k++){
					//cout<<a.top()<<" ";
					a.pop();
				}
				//cout<<endl;
			}
//			stack<int> aaa;
//			for(int k=1;k<=a.size();k++){
//				aaa.push(a.top());
//				cout<<a.top()<<" ";
//				a.pop();
//			}
//			for(int k=1;k<=aaa.size();k++){
//				a.push(aaa.top());
//				aaa.pop();
//			}
//			cout<<"\n";
		}
		for(int j=1;j<=a.size();j++){
			//cout<<"i:"<<i<<" j:"<<j<<" "<<a.top()<<"\n";
			ans[a.top()]++;
			a.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0; 
}

