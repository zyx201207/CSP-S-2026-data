#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	stack<int> s;
	int shu[100001]={0};
	int you[100001]={0};
	int ka[200001]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ka[i];
	}
	
	//cout<<n<<m<<endl<<endl;
	
	for(int i=0;i<n;i++){
		//cout<<"i di"<<i<<endl;
		
		for(int j=i;j<n;j++){
			
			//cout<<"j di"<<j<<endl;
			if(you[ka[j]-1]==0){
				//cout<<"wu"<<endl;
				s.push(ka[j]);
				you[ka[j]-1]=1;
				//cout<<"加入"<<ka[j]<<endl;
			}
			
			else{
				//cout<<"you"<<endl;
				while(s.top()!=ka[j]){
					//cout<<"删除"<<s.top()<<endl;
					you[s.top()-1]=0;
					s.pop();
				}//cout<<"删除"<<s.top()<<endl;
				s.pop();
				//cout<<"加入"<<ka[j]<<endl;
				s.push(ka[j]);
			}
			//cout<<"yes"<<endl;
		}
		
		
		while(!s.empty()){
			//cout<<"....."<<s.top()-1<<"..."<<endl;			
			shu[s.top()-1]+=1;
			you[s.top()-1]=0;
			s.pop();
		}
		/*cout<<"shuchuyou"<<endl;
		for(int i=0;i<m;i++){
			cout<<shu[i]<<" "<<you[i]<<" "<<endl;
		}*/
	
	
	
	}
	
	//cout<<"结束"<<endl;
	
	for(int i=0;i<m;i++){ 
		cout<<shu[i]<<" ";
	}
	
	
	
	return 0;
}
