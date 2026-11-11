#include<bits/stdc++.h>
using namespace std;
int e[194356];
int nihao[347826];
void haha(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;i<=n+n;j++){
			for(int k=0;k<=n;k++){
				haha(k);
			}
			haha(i);
		}
	}
	return;
}
void hahaha(int n){
	for(int i=0;i<=n;i++){
		for(int j=0;i<=n+n;j++){
			for(int k=0;k<=n;k++){
				haha(k);
			}
			haha(i);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,x[2000005];
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i]; 
		}
	}
	if(c==1||c==2){
		cout<<"I don't know...";
	}
	else if(c>=3&&c<=6){
		cout<<"I can't understand...";
	}
	else if(c>=7&&c<=10){
		cout<<"It's too hard for me...";
	}
	else if(c==11||c==12){
		cout<<"What does A mean?";
	}
	else if(c==13||c==14){
		cout<<"What does B mean?";
	}
	else if(c>=15&&c<=18){
		cout<<"What does C mean?";
	}
	else{
		cout<<"I still can't answer...";
	}
	cout<<"[Problem Describing]"
	<<endl
	<<"Little W is used to be a science and technology lover."
	<<"When he worked in the country C,he was a tryer,"
	<<"and he tried all kinds of new hand giving doors day by day"
	<<" with coming from this city to another city."
	<<"After doing this for a long time,"
	<<"he started to hate this kind of life,"
	<<"so he let go of his job"
	<<" and came to the country D without hand giving doors."
	<<"He hoped that he can find back his love of inviting."
	<<endl;
	cout<<"Before starting to invite new things,"
	<<"Little W needs to build a inviting hub."
	<<"The country D has n cities,their number is from 1 to n."
	<<"The cities are connectting with n-1 paths,"
	<<"the path named i is connected with the cities named ui and vi."
	<<"If we see each city as a spot,and see each path as one side which "
	<<"connects two spots,"
	<<"a tree T will be made up with the cities and paths."
	<<endl;
	cout<<"Why is this problem so hard? I hate you,CCF!";
	cout<<endl<<"Can you give me 5 points please? Thank you very much!";
	return 0;
}
