#include <iostream>
using namespace std;
int c;
int t;
int n;
int d;
int count;

int main(){
	cin>>c;
	cin>>t;
	int answer[t];
	for (int i=0;i<t;i++){
		
		count=0;
		cin>>n;
		cin>>d;
		int loc[n];
		for (int j=0;j<n;j++){
			cin>>loc[j];
		}
		for(int j=0;j<n;j++){
			
			for(int k=0;k<n;k++){
				if ((loc[k]-loc[j])/d==1 and (loc[k]-loc[j])%d!=0){
					count++;
					//cout<<loc[k]<<' '<<loc[j];
				}
			}
			
		}
		answer[i]=count;
	}
	for (int i=0;i<t;i++){
		cout<<answer[i]<<endl;
	}
	return 0; 
}
