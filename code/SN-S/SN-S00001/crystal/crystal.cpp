#include<bits/stdc++.h>

using namespace std;
int q[500005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=0;
	int m=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	
	int a=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				for(int o=0;o<n;o++){
					for(int l=0;l<n;l++){
						if(q[i]>=q[j]){
							a=q[i];
							q[i]=q[j];
							q[j]=a;
						}
						if(q[i]>=q[k]){
							a=q[i];
							q[i]=q[k];
							q[k]=a;
						}
						if(q[i]>=q[o]){
							a=q[i];
							q[i]=q[o];
							q[o]=a;
						}
						if(q[i]>=q[l]){
							a=q[i];
							q[i]=q[l];
							q[j]=a;
						}
					}
				}
			}
		}
	}

	if(n==1){
		cout<<"1"<<endl;
	}else if(n==2){
		if(q[1]>=q[0]){
			if(q[1]-q[0]>m){
				cout<<"1"<<endl;
			}else if(q[1]-q[0]<=m&&q[1]-q[0]>=0){
				cout<<"2"<<endl;
			}
		}else{
			if(q[0]-q[1]>m){
				cout<<"1"<<endl;
			}else if(q[0]-q[1]<=m&&q[0]-q[1]>=0){
				cout<<"2"<<endl;
			}
		}	
	}else if(n==3){
		if(q[2]>=q[1]>=q[0]){
		if((q[2]-q[0])+(q[2]-q[1])>=m){
			cout<<"3"<<"\n";
		}else if(q[2]-q[1]>=m||q[2]-q[0]>=m||q[1]-q[0]>=m){
			cout<<"2"<<endl;
		}else{
			cout<<"1"<<endl;
		}
		
		}else{
			cout<<"2"<<endl;
		}
    }else if(n==4){
    	if((q[3]-q[2])+(q[3]-q[1])+(q[3]-q[0])>=m){
    		cout<<"4"<<"\n";
		}else if((q[2]-q[1])+(q[2]-q[0])>=m||
				(q[3]-q[1])+(q[3]-q[0])>=m||
				(q[3]-q[1])+(q[3]-q[2])){
			cout<<"3"<<"\n";
		}else if(q[1]-q[0]>=m||q[2]-q[0]>=m||q[3]-q[0]>=m||
				q[2]-q[1]>=m||q[3]-q[1]>=0||
				q[3]-q[2]>=m){
			cout<<"2"<<"\n";	
		}else{
			cout<<"1"<<"\n";
		}
	}else if(n==5){
		if((q[4]-q[3])+(q[4]-q[2])+(q[4]-q[2])+(q[4]-q[1])+(q[4]-q[0])>=m){
			cout<<"5"<<"\n";
		}
		 if((q[3]-q[2])+(q[3]-q[1])+(q[3]-q[0])>=m||
				(q[4]-q[2])+(q[4]-q[1])+(q[4]-q[0])>=m||
				(q[4]-q[3])+(q[4]-q[1])+(q[4]-q[0])>=m||
				(q[4]-q[2])+(q[4]-q[3])+(q[4]-q[0])>=m||
				(q[4]-q[2])+(q[4]-q[1])+(q[4]-q[3])>=m){
			cout<<"4"<<"\n";
		}else{
			cout<<"3"<<endl;
		}
	}
	return 0;
} 
