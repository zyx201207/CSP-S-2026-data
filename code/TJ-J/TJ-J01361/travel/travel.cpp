 #include <bits/stdc++.h>
 using namespace std;
 struct f{
 	int a;
 	char b1;
 	char b2;
 	char b3;
 };
 
 
 int main (){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	
 	f r;
 	f x;
 	cin>>r.a>>r.b1>>r.b2>>r.b3>>x.a>>x.b1>>x.b2>>x.b3;
 	if (r.a==x.a){
 		cout<<"1";
 		int sum1=r.b1;
 		int sum2=r.b2;
 		int sum3=r.b3;
 		int sum4=x.b1;
 		int sum5=x.b2;
 		int  sum6=x.b3;
 		if (sum1==sum4&&sum2==sum5){
 			cout<<"1";
 			if (sum3<='C'&&sum6<='C'){
 				cout<<"1";
			 }else if(sum3>='D'&&sum6>='D'){
			 	cout<<"1";
			 }else{
			 	cout<<"00";
			 	return 0;
			 }
			 if (sum3-sum6==1||sum3-sum6==-1){
			 	cout<<"1";
			 }else{
			 	cout<<"0";
			 }
			 
		 }else{
		 	cout<<"000";
		 	return 0;
		 }
	 }else{
	 	cout<<"0000";
	 	return 0;
	 }
 	
 	
 	
 	
 	
 	
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
