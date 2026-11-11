#include<bits/stdc++.h>
using namespace std;
long long n,a[20005],m,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(long long i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	if(m==n)
	{
		ans=a[1];
		for(long long i=1;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	if(m==2)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				ans=max(ans, a[i]&a[j]); 
			}
		}
	}
	if(m==3)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					ans=max(ans,a[i]&a[j]&a[k]);
				} 
			}
		}
	}
	if(m==4) 
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						ans=max(ans,a[i]&a[j]&a[k]&a[k1]);
					}
				} 
			}
		}
	}
	if(m==5)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]);
						}
					}
				} 
			}
		}
	}
	if(m==6)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]);
							}
						}
					}
				} 
			}
		}
	}
	if(m==7)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]);
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==8)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]);
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==9)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]);
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==10)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]);
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==11)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]);
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==12)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]);
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==13)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]);
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==14)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]);
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==15)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																for(long long k12=k11+1;k12<=n;k12++)
																{
																	ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]);
																}
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==16)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																for(long long k12=k11+1;k12<=n;k12++)
																{
																	for(long long k13=k12+1;k13<=n;k13++)
																	{
																		ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]);
																	}
																}
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==17)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																for(long long k12=k11+1;k12<=n;k12++)
																{
																	for(long long k13=k12+1;k13<=n;k13++)
																	{
																		for(long long k14=k13+1;k14<=n;k14++)
																		{
																			ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]);
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==18)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																for(long long k12=k11+1;k12<=n;k12++)
																{
																	for(long long k13=k12+1;k13<=n;k13++)
																	{
																		for(long long k14=k13+1;k14<=n;k14++)
																		{
																			for(long long k15=k14+1;k15<=n;k15++)
																			{
																				ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]&a[k15]);
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==19)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																for(long long k12=k11+1;k12<=n;k12++)
																{
																	for(long long k13=k12+1;k13<=n;k13++)
																	{
																		for(long long k14=k13+1;k14<=n;k14++)
																		{
																			for(long long k15=k14+1;k15<=n;k15++)
																			{
																				for(long long k16=k15+1;k16<=m;k16++)
																				{
																					ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]&a[k15]&a[k16]);
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	if(m==20)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				for(long long k=j+1;k<=n;k++)
				{
					for(long long k1=k+1;k1<=n;k1++)
					{
						for(long long k2=k1+1;k2<=n;k2++)
						{
							for(long long k3=k2+1;k3<=n;k3++)
							{
								for(long long k4=k3+1;k4<=n;k4++)
								{
									for(long long k5=k4+1;k5<=n;k5++)
									{
										for(long long k6=k5+1;k6<=n;k6++)
										{
											for(long long k7=k6+1;k7<=n;k7++)
											{
												for(long long k8=k7+1;k8<=n;k8++)
												{
													for(long long k9=k8+1;k9<=n;k9++)
													{
														for(long long k10=k9+1;k10<=n;k10++)
														{
															for(long long k11=k10+1;k11<=n;k11++)
															{
																for(long long k12=k11+1;k12<=n;k12++)
																{
																	for(long long k13=k12+1;k13<=n;k13++)
																	{
																		for(long long k14=k13+1;k14<=n;k14++)
																		{
																			for(long long k15=k14+1;k15<=n;k15++)
																			{
																				for(long long k16=k15+1;k16<=n;k16++)
																				{
																					for(long long k17=k16+1;k17<=n;k17++)
																					{
																						ans=max(ans,a[i]&a[j]&a[k]&a[k1]&a[k2]&a[k3]&a[k4]&a[k5]&a[k6]&a[k7]&a[k8]&a[k9]&a[k10]&a[k11]&a[k12]&a[k13]&a[k14]&a[k15]&a[k16]&a[k17]);
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									} 
								}
							}
						}
					}
				} 
			}
		}
	}
	cout<<ans;
	return 0;
} 
