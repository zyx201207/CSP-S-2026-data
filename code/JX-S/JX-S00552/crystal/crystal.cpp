/*
 * crystal.cpp
 * 
 * Copyright 2026 NOI <noi@G18-D07>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("math","r","crystal.in");
	freopen("math","w","crystal.out");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=1,b=0,c=1,d=0,v=0,sum=0;
	while(x!=0){
		for(int i=2;i<=n-c;i++){
			b+=a[i];
			d++;
		}
		if(a[n-v]-b==m){
			sum=d;
			x=0;
		}
		else{
			continue;
		}
		v++;
	}
	cout<<sum;
	return 0;
}

