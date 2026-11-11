#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> arr(n+1,0);
	for(int i=1;i<=n;i++){
        cin>>arr[i];
	}
	int i=1,l=n;
	vector<int> ans(m+1,0);
	while(n--){
        vector<int> temp;
        for(int j=i;j<=l;j++){
            bool flag=false;
            int c=0;
           while(!temp.empty()){
                if(temp.back()==arr[j]){
                    flag=true;
                    c++;
                    break;
                }
                c++;
           }
           if(flag){
             while(c--)temp.pop_back();
             temp.push_back(arr[j]);
           }
           else temp.push_back(arr[j]);
        }
        while(temp.empty()){
            ans[temp.back()]++;
            temp.pop_back();
        }
        i++;
	}
	for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
