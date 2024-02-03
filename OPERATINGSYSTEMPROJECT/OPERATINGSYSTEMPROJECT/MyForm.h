
#pragma once
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>


namespace OPERATINGSYSTEMPROJECT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	struct Process {
		int id;
		int arrivalTime;
		int burstTime;
		int startTime;
		int completionTime;
		int turnaroundTime;
		int waitingTime;
		int responseTime;
		int priority;
		int remainingTime;
	};

	// Comparison functions for sorting processes
	bool sortByArrival(const Process& a, const Process& b) {
		return a.arrivalTime < b.arrivalTime;
	}

	bool sortByOriginalOrder(const Process& a, const Process& b) {
		return a.id < b.id;
	}

	
	// Comparison functions for sorting processes
	bool compareArrival(Process p1, Process p2) {
		return p1.arrivalTime < p2.arrivalTime;
	}

	bool compareID(Process p1, Process p2) {
		return p1.id < p2.id;
	}


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::RadioButton^ rbFCFS;
	private: System::Windows::Forms::RadioButton^ rbnpp;
	private: System::Windows::Forms::RadioButton^ rbSRTF;

	private: System::Windows::Forms::GroupBox^ gbAlgo;















	private: System::Windows::Forms::ListBox^ lbDisplay;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::DataGridView^ dgDisplay;
	private: System::Windows::Forms::TextBox^ tbBT;
	private: System::Windows::Forms::TextBox^ tbAT;
	private: System::Windows::Forms::Button^ btnCompute;
	private: System::Windows::Forms::Label^ lblAT;
	private: System::Windows::Forms::Label^ lblBT;
	private: System::Windows::Forms::TextBox^ tbprio;
	private: System::Windows::Forms::Label^ lblPrio;
	private: System::Windows::Forms::Label^ lblAlgo;
	private: System::Windows::Forms::Label^ lblHistory;
	private: System::Windows::Forms::Label^ lblATT;
	private: System::Windows::Forms::Label^ lblAWT;
	private: System::Windows::Forms::Label^ lblCPU;
	private: System::Windows::Forms::Label^ lblDisp;







	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->rbFCFS = (gcnew System::Windows::Forms::RadioButton());
			this->rbnpp = (gcnew System::Windows::Forms::RadioButton());
			this->rbSRTF = (gcnew System::Windows::Forms::RadioButton());
			this->gbAlgo = (gcnew System::Windows::Forms::GroupBox());
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->dgDisplay = (gcnew System::Windows::Forms::DataGridView());
			this->tbBT = (gcnew System::Windows::Forms::TextBox());
			this->tbAT = (gcnew System::Windows::Forms::TextBox());
			this->btnCompute = (gcnew System::Windows::Forms::Button());
			this->lblAT = (gcnew System::Windows::Forms::Label());
			this->lblBT = (gcnew System::Windows::Forms::Label());
			this->tbprio = (gcnew System::Windows::Forms::TextBox());
			this->lblPrio = (gcnew System::Windows::Forms::Label());
			this->lblAlgo = (gcnew System::Windows::Forms::Label());
			this->lblHistory = (gcnew System::Windows::Forms::Label());
			this->lblATT = (gcnew System::Windows::Forms::Label());
			this->lblAWT = (gcnew System::Windows::Forms::Label());
			this->lblCPU = (gcnew System::Windows::Forms::Label());
			this->lblDisp = (gcnew System::Windows::Forms::Label());
			this->gbAlgo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDisplay))->BeginInit();
			this->SuspendLayout();
			// 
			// rbFCFS
			// 
			this->rbFCFS->AutoSize = true;
			this->rbFCFS->Location = System::Drawing::Point(18, 19);
			this->rbFCFS->Name = L"rbFCFS";
			this->rbFCFS->Size = System::Drawing::Size(127, 17);
			this->rbFCFS->TabIndex = 1;
			this->rbFCFS->TabStop = true;
			this->rbFCFS->Text = L"First Come First Serve";
			this->rbFCFS->UseVisualStyleBackColor = true;
			this->rbFCFS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbFCFS_CheckedChanged);
			// 
			// rbnpp
			// 
			this->rbnpp->AutoSize = true;
			this->rbnpp->Location = System::Drawing::Point(18, 42);
			this->rbnpp->Name = L"rbnpp";
			this->rbnpp->Size = System::Drawing::Size(135, 17);
			this->rbnpp->TabIndex = 2;
			this->rbnpp->TabStop = true;
			this->rbnpp->Text = L"Non Preemprive Priority";
			this->rbnpp->UseVisualStyleBackColor = true;
			this->rbnpp->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbnpp_CheckedChanged);
			// 
			// rbSRTF
			// 
			this->rbSRTF->AutoSize = true;
			this->rbSRTF->Location = System::Drawing::Point(18, 65);
			this->rbSRTF->Name = L"rbSRTF";
			this->rbSRTF->Size = System::Drawing::Size(165, 17);
			this->rbSRTF->TabIndex = 3;
			this->rbSRTF->TabStop = true;
			this->rbSRTF->Text = L"Shortest Remaining Time First";
			this->rbSRTF->UseVisualStyleBackColor = true;
			this->rbSRTF->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbSRTF_CheckedChanged);
			// 
			// gbAlgo
			// 
			this->gbAlgo->Controls->Add(this->rbSRTF);
			this->gbAlgo->Controls->Add(this->rbFCFS);
			this->gbAlgo->Controls->Add(this->rbnpp);
			this->gbAlgo->Location = System::Drawing::Point(24, 302);
			this->gbAlgo->Name = L"gbAlgo";
			this->gbAlgo->Size = System::Drawing::Size(198, 90);
			this->gbAlgo->TabIndex = 4;
			this->gbAlgo->TabStop = false;
			this->gbAlgo->Text = L"Algorithm";
			this->gbAlgo->Enter += gcnew System::EventHandler(this, &MyForm::gbAlgo_Enter);
			// 
			// lbDisplay
			// 
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->Location = System::Drawing::Point(238, 357);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(553, 225);
			this->lbDisplay->TabIndex = 6;
			this->lbDisplay->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::lbDisplay_SelectedIndexChanged_1);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(80, 458);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(89, 36);
			this->btnClear->TabIndex = 7;
			this->btnClear->Text = L"Clear History";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// dgDisplay
			// 
			this->dgDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgDisplay->Location = System::Drawing::Point(238, 56);
			this->dgDisplay->Name = L"dgDisplay";
			this->dgDisplay->Size = System::Drawing::Size(627, 230);
			this->dgDisplay->TabIndex = 8;
			this->dgDisplay->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dgDisplay_CellContentClick);
			// 
			// tbBT
			// 
			this->tbBT->Location = System::Drawing::Point(34, 158);
			this->tbBT->Name = L"tbBT";
			this->tbBT->Size = System::Drawing::Size(188, 20);
			this->tbBT->TabIndex = 1;
			// 
			// tbAT
			// 
			this->tbAT->Location = System::Drawing::Point(34, 115);
			this->tbAT->Name = L"tbAT";
			this->tbAT->Size = System::Drawing::Size(188, 20);
			this->tbAT->TabIndex = 0;
			// 
			// btnCompute
			// 
			this->btnCompute->Location = System::Drawing::Point(80, 241);
			this->btnCompute->Name = L"btnCompute";
			this->btnCompute->Size = System::Drawing::Size(89, 36);
			this->btnCompute->TabIndex = 2;
			this->btnCompute->Text = L"Compute";
			this->btnCompute->UseVisualStyleBackColor = true;
			this->btnCompute->Click += gcnew System::EventHandler(this, &MyForm::btnCompute_Click);
			// 
			// lblAT
			// 
			this->lblAT->AutoSize = true;
			this->lblAT->Location = System::Drawing::Point(30, 99);
			this->lblAT->Name = L"lblAT";
			this->lblAT->Size = System::Drawing::Size(62, 13);
			this->lblAT->TabIndex = 3;
			this->lblAT->Text = L"Arrival Time";
			// 
			// lblBT
			// 
			this->lblBT->AutoSize = true;
			this->lblBT->Location = System::Drawing::Point(30, 142);
			this->lblBT->Name = L"lblBT";
			this->lblBT->Size = System::Drawing::Size(57, 13);
			this->lblBT->TabIndex = 4;
			this->lblBT->Text = L"Burst Time";
			// 
			// tbprio
			// 
			this->tbprio->Location = System::Drawing::Point(34, 206);
			this->tbprio->Name = L"tbprio";
			this->tbprio->Size = System::Drawing::Size(188, 20);
			this->tbprio->TabIndex = 5;
			this->tbprio->TextChanged += gcnew System::EventHandler(this, &MyForm::tbprio_TextChanged);
			// 
			// lblPrio
			// 
			this->lblPrio->AutoSize = true;
			this->lblPrio->Location = System::Drawing::Point(30, 190);
			this->lblPrio->Name = L"lblPrio";
			this->lblPrio->Size = System::Drawing::Size(38, 13);
			this->lblPrio->TabIndex = 6;
			this->lblPrio->Text = L"Priority";
			// 
			// lblAlgo
			// 
			this->lblAlgo->AutoSize = true;
			this->lblAlgo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAlgo->Location = System::Drawing::Point(242, 9);
			this->lblAlgo->Name = L"lblAlgo";
			this->lblAlgo->Size = System::Drawing::Size(199, 31);
			this->lblAlgo->TabIndex = 9;
			this->lblAlgo->Text = L"Welcome User!";
			// 
			// lblHistory
			// 
			this->lblHistory->AutoSize = true;
			this->lblHistory->Location = System::Drawing::Point(235, 341);
			this->lblHistory->Name = L"lblHistory";
			this->lblHistory->Size = System::Drawing::Size(39, 13);
			this->lblHistory->TabIndex = 10;
			this->lblHistory->Text = L"History";
			// 
			// lblATT
			// 
			this->lblATT->AutoSize = true;
			this->lblATT->Location = System::Drawing::Point(461, 302);
			this->lblATT->Name = L"lblATT";
			this->lblATT->Size = System::Drawing::Size(141, 13);
			this->lblATT->TabIndex = 11;
			this->lblATT->Text = L"Average Turn Around Time: ";
			this->lblATT->Click += gcnew System::EventHandler(this, &MyForm::lblATT_Click);
			// 
			// lblAWT
			// 
			this->lblAWT->AutoSize = true;
			this->lblAWT->Location = System::Drawing::Point(461, 325);
			this->lblAWT->Name = L"lblAWT";
			this->lblAWT->Size = System::Drawing::Size(118, 13);
			this->lblAWT->TabIndex = 12;
			this->lblAWT->Text = L"Average Waiting Time: ";
			// 
			// lblCPU
			// 
			this->lblCPU->AutoSize = true;
			this->lblCPU->Location = System::Drawing::Point(678, 302);
			this->lblCPU->Name = L"lblCPU";
			this->lblCPU->Size = System::Drawing::Size(83, 13);
			this->lblCPU->TabIndex = 13;
			this->lblCPU->Text = L"CPU Utilization: ";
			// 
			// lblDisp
			// 
			this->lblDisp->AutoSize = true;
			this->lblDisp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDisp->Location = System::Drawing::Point(21, 34);
			this->lblDisp->Name = L"lblDisp";
			this->lblDisp->Size = System::Drawing::Size(200, 17);
			this->lblDisp->TabIndex = 14;
			this->lblDisp->Text = L"Process Scheduling Algorithm:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(930, 625);
			this->Controls->Add(this->lblDisp);
			this->Controls->Add(this->lblCPU);
			this->Controls->Add(this->lblAWT);
			this->Controls->Add(this->lblATT);
			this->Controls->Add(this->lblHistory);
			this->Controls->Add(this->lblAlgo);
			this->Controls->Add(this->lblPrio);
			this->Controls->Add(this->tbprio);
			this->Controls->Add(this->dgDisplay);
			this->Controls->Add(this->lblBT);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->lblAT);
			this->Controls->Add(this->lbDisplay);
			this->Controls->Add(this->btnCompute);
			this->Controls->Add(this->gbAlgo);
			this->Controls->Add(this->tbAT);
			this->Controls->Add(this->tbBT);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->gbAlgo->ResumeLayout(false);
			this->gbAlgo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDisplay))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion

		String^ stdDetails;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}


private: System::Void btnCompute_Click(System::Object^ sender, System::EventArgs^ e) {
	//check the algo before computation

	if (rbFCFS->Checked) {
		// Declare variables to store process information and various metrics
		int numProcesses;
		vector<Process> processes;
		float avgTurnaroundTime, avgWaitingTime, avgResponseTime, cpuUtilization, throughput;
		int totalTurnaroundTime = 0, totalWaitingTime = 0, totalResponseTime = 0, totalIdleTime = 0;
		String^ tempBurstTime, ^ tempArrivalTime = "";

		// Input handling for arrival times
		tempArrivalTime = tbAT->Text;
		string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
		istringstream iss(arrivalTimeStr);

		// Read arrival times and store them in the 'at' vector
		vector<int> at;
		char comma;  // Variable to store the comma
		for (int number; iss >> number || (iss.eof() && at.empty());) {
			at.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (iss >> std::ws && iss.peek() == ',') {
				iss.ignore();
			}
		}

		// Input handling for burst times
		tempBurstTime = tbBT->Text;
		std::string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBurstTime);
		istringstream isss(burstTimeStr);

		// Read burst times and store them in the 'bt' vector
		vector<int> bt;
		for (int number; isss >> number || (isss.eof() && bt.empty());) {
			bt.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (isss >> std::ws && isss.peek() == ',') {
				isss.ignore();
			}
		}

		// Validation to check if the number of bt and at is the same, if not exit
		if (at.size() != bt.size()) {
			MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Initialize the number of processes
		numProcesses = at.size();

		// Store the values to the struct process
		for (int i = 0; i < numProcesses; i++) {
			Process process;
			process.id = i + 1;  // Assign a unique id
			process.arrivalTime = at[i];
			process.burstTime = bt[i];
			processes.push_back(process);
		}

		// Sort processes based on arrival time
		sort(processes.begin(), processes.end(), compareArrival);

		// Calculate various metrics for each process
		for (int i = 0; i < numProcesses; i++) {
			processes[i].startTime = (i == 0) ? processes[i].arrivalTime : max(processes[i - 1].completionTime, processes[i].arrivalTime);
			processes[i].completionTime = processes[i].startTime + processes[i].burstTime;
			processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
			processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
			processes[i].responseTime = processes[i].startTime - processes[i].arrivalTime;

			// Update cumulative metrics
			totalTurnaroundTime += processes[i].turnaroundTime;
			totalWaitingTime += processes[i].waitingTime;
			totalResponseTime += processes[i].responseTime;
			totalIdleTime += (i == 0) ? processes[i].arrivalTime : (processes[i].startTime - processes[i - 1].completionTime);
		}

		// Calculate average metrics
		avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
		avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
		avgResponseTime = static_cast<float>(totalResponseTime) / numProcesses;
		cpuUtilization = ((processes[numProcesses - 1].completionTime - totalIdleTime) / static_cast<float>(processes[numProcesses - 1].completionTime)) * 100;
		throughput = static_cast<float>(numProcesses) / (processes[numProcesses - 1].completionTime - processes[0].arrivalTime);

		// Sort processes based on ID for output display
		sort(processes.begin(), processes.end(), compareID);

		// Display process information in tabular format
		stdDetails = "{0, -15}{1, -22}{2, -22}{3, -26}{4, -26}{5, -26}{6, -26}";
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", "                      First Come First Serve", " ", " ", " "));
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time", "Priority"));
		
		for (const Process& p : processes) {
			stdDetails = "{0, -25}{1, -30}{2, -30}{3, -33}{4, -33}{5, -33}{6, -33}";
			lbDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime, " "));

		}
		lbDisplay->Items->Add(" "); 

		// for allignment
		stdDetails = "{0, -15}{1, -25}{2, -25}{3, -25}{4, -25}{5, -25}{6, -25}";
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", "Average Waiting Time: ", avgWaitingTime, "Average Turn Around time:", avgTurnaroundTime, " "));

		lbDisplay->Items->Add(" ");

		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", " ", "CPU Utilization: ", cpuUtilization, " %", " "));		

		//diplay average
		lblATT->Text = "Average Turn Around Time: " + avgTurnaroundTime.ToString();
		lblAWT->Text = "Average Waiting Time: " + avgTurnaroundTime.ToString();
		lblCPU->Text = "CPU Utilization: " + cpuUtilization.ToString() + " %";

		//space
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(" ");

		//data grid
		// Assuming dtDisplay is your DataGridView control
		dgDisplay->Rows->Clear();
		dgDisplay->Columns->Clear();

		// Add columns to the DataGridView
		dgDisplay->Columns->Add("PID", "Process ID");
		dgDisplay->Columns->Add("ArrivalTime", "Arrival Time");
		dgDisplay->Columns->Add("BurstTime", "Burst Time");
		dgDisplay->Columns->Add("CompletionTime", "Completion Time");
		dgDisplay->Columns->Add("TurnaroundTime", "Turn Around Time");
		dgDisplay->Columns->Add("WaitingTime", "Waiting Time");
		

		// Display process information in DataGridView
		for (const Process& p : processes) {
			dgDisplay->Rows->Add(p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime);
		}

	}

	// NPP ALGO
	else if (rbnpp->Checked) {
		int numProcesses;
		vector<Process> processes;
		float avgTurnaroundTime;
		float avgWaitingTime;
		float avgResponseTime;
		float cpuUtilization;
		int totalTurnaroundTime = 0;
		int totalWaitingTime = 0;
		int totalResponseTime = 0;
		int totalIdleTime = 0;
		float throughput;
		vector<int> isCompleted;
		String^ tempBurstTime,^ tempArrivalTime,^ tempPriority;

		tempArrivalTime = tbAT->Text;
		string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
		istringstream iss(arrivalTimeStr);

		// Read arrival times and store them in the 'at' vector
		vector<int> at;
		char comma;  // Variable to store the comma
		for (int number; iss >> number || (iss.eof() && at.empty());) {
			at.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (iss >> std::ws && iss.peek() == ',') {
				iss.ignore();
			}
		}

		// Input handling for burst times
		tempBurstTime = tbBT->Text;
		std::string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBurstTime);
		istringstream isss(burstTimeStr);

		// Read burst times and store them in the 'bt' vector
		vector<int> bt;
		for (int number; isss >> number || (isss.eof() && bt.empty());) {
			bt.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (isss >> std::ws && isss.peek() == ',') {
				isss.ignore();
			}
		}


		// Input handling for priority
		tempPriority = tbprio->Text;
		std::string priorityStr = msclr::interop::marshal_as<std::string>(tempPriority);
		istringstream issss(priorityStr);

		// Read priority times and store them in the 'priority' vector
		vector<int> priority;
		for (int number; issss >> number || (issss.eof() && bt.empty());) {
			priority.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (issss >> std::ws && issss.peek() == ',') {
				issss.ignore();
			}
		}

		// Validation to check if the number of bt and at is the same, if not exit
		if (priority.size() != bt.size()) {
			MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// Initialize the number of processes
		numProcesses = at.size();

		// Store the values to the struct process
		for (int i = 0; i < numProcesses; i++) {
			Process process;
			process.id = i + 1;  // Assign a unique id
			process.arrivalTime = at[i];
			process.burstTime = bt[i];
			process.priority = priority[i];
			processes.push_back(process);
		}

		isCompleted.resize(numProcesses, 0);  // Initialize isCompleted vector

		int currentTime = 0;
		int completed = 0;
		int prev = 0;

		// Calculate additional metrics
		int minArrivalTime = 10000000;
		int maxCompletionTime = -1; 

		// Schedule processes using Priority Scheduling
		while (completed != numProcesses) {
			int idx = -1;
			int mx = 1000000000; // set mx to a high value

			// Find the process with the highest priority that has arrived
			for (int i = 0; i < numProcesses; i++) {
				if (processes[i].arrivalTime <= currentTime && isCompleted[i] == 0) {
					if (processes[i].priority < mx) {
						mx = processes[i].priority;
						idx = i;
					}
					if (processes[i].priority == mx) {
						if (processes[i].arrivalTime < processes[idx].arrivalTime) {
							mx = processes[i].priority;
							idx = i;
						}
					}
				}
			}

			
			// Execute the selected process
			if (idx != -1) {
				processes[idx].startTime = currentTime;
				processes[idx].completionTime = processes[idx].startTime + processes[idx].burstTime;
				processes[idx].turnaroundTime = processes[idx].completionTime - processes[idx].arrivalTime;
				processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
				processes[idx].responseTime = processes[idx].startTime - processes[idx].arrivalTime;

				maxCompletionTime = max(maxCompletionTime, processes[idx].completionTime);
				minArrivalTime = min(minArrivalTime, processes[idx].arrivalTime);


				totalTurnaroundTime += processes[idx].turnaroundTime;
				totalWaitingTime += processes[idx].waitingTime;
				totalResponseTime += processes[idx].responseTime;
				totalIdleTime += processes[idx].startTime - prev;

				isCompleted[idx] = 1;
				completed++;
				currentTime = processes[idx].completionTime;
				prev = currentTime;
			}
			else {
				currentTime++;
			}
		}


		avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
		avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
		avgResponseTime = static_cast<float>(totalResponseTime) / numProcesses;
		cpuUtilization = ((maxCompletionTime - totalIdleTime) / static_cast<float>(maxCompletionTime)) * 100;
		throughput = static_cast<float>(numProcesses) / (maxCompletionTime - minArrivalTime);


		// Display process information in tabular format
		stdDetails = "{0, -15}{1, -22}{2, -22}{3, -26}{4, -26}{5, -26}{6, -26}";
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", "                      Non Preemptive Priority", " ", " ", " "));
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time", "Priority"));

		for (const Process& p : processes) {
			stdDetails = "{0, -25}{1, -30}{2, -30}{3, -33}{4, -33}{5, -33}{6, -33}";
			lbDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime,  + p.priority));
		}

		lbDisplay->Items->Add(" ");

		// for allignment
		stdDetails = "{0, -15}{1, -25}{2, -25}{3, -25}{4, -25}{5, -25}{6, -25}";
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", "Average Waiting Time: ", avgWaitingTime, "Average Turn Around time:", avgTurnaroundTime, " "));

		lbDisplay->Items->Add(" ");

		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", " ", "CPU Utilization: ", cpuUtilization, " %", " "));

		//diplay average
		lblATT->Text = "Average Turn Around Time: " + avgTurnaroundTime.ToString();
		lblAWT->Text = "Average Waiting Time: " + avgTurnaroundTime.ToString();
		lblCPU->Text = "CPU Utilization: " + cpuUtilization.ToString() + " %";

		//space
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(" ");

		//data grid
		// Assuming dtDisplay is your DataGridView control
		dgDisplay->Rows->Clear();
		dgDisplay->Columns->Clear();

		// Add columns to the DataGridView
		dgDisplay->Columns->Add("PID", "Process ID");
		dgDisplay->Columns->Add("ArrivalTime", "Arrival Time");
		dgDisplay->Columns->Add("BurstTime", "Burst Time");
		dgDisplay->Columns->Add("Priority", "Priority");
		dgDisplay->Columns->Add("CompletionTime", "Completion Time");
		dgDisplay->Columns->Add("TurnaroundTime", "Turn Around Time");
		dgDisplay->Columns->Add("WaitingTime", "Waiting Time");


		// Display process information in DataGridView
		for (const Process& p : processes) {
			dgDisplay->Rows->Add(p.id, p.arrivalTime, p.burstTime, p.priority, p.completionTime, p.turnaroundTime, p.waitingTime);
		}
	}


	// SRTF
	else if (rbSRTF->Checked) {
		int numProcesses;
		vector<Process> processes;
		float avgTurnaroundTime, avgWaitingTime, cpuUtilization;
		int totalTurnaroundTime = 0, totalWaitingTime = 0, totalIdleTime = 0;
		String^ tempBursttime,^ tempArrivalTime;

		// Input handling for arrival times
		tempArrivalTime = tbAT->Text;
		string arrivalTimeStr = msclr::interop::marshal_as<std::string>(tempArrivalTime);
		istringstream iss(arrivalTimeStr);

		// Read arrival times and store them in the 'at' vector
		vector<int> at;
		char comma;  // Variable to store the comma
		for (int number; iss >> number || (iss.eof() && at.empty());) {
			at.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (iss >> std::ws && iss.peek() == ',') {
				iss.ignore();
			}
		}

		// Input handling for burst times
		tempBursttime = tbBT->Text;
		std::string burstTimeStr = msclr::interop::marshal_as<std::string>(tempBursttime);
		istringstream isss(burstTimeStr);

		// Read burst times and store them in the 'bt' vector
		vector<int> bt;
		for (int number; isss >> number || (isss.eof() && bt.empty());) {
			bt.push_back(number);

			// Check for a comma and consume it if not at the end of the input
			if (isss >> std::ws && isss.peek() == ',') {
				isss.ignore();
			}
		}

		// Validation to check if the number of bt and at is the same, if not exit
		if (at.size() != bt.size()) {
			MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		
		// Initialize the number of processes
		numProcesses = at.size();

		// Store the values to the struct process
		for (int i = 0; i < numProcesses; i++) {
			Process process;
			process.id = i + 1;  // Assign a unique id
			process.arrivalTime = at[i];
			process.burstTime = bt[i];
			process.remainingTime = process.burstTime;

			processes.push_back(process);
		}


		// Sort processes by arrival time
		sort(processes.begin(), processes.end(), sortByArrival);

		int currentTime = 0;
		int completedProcesses = 0;
		vector<int> ganttChart;

		while (completedProcesses < numProcesses) {
			int shortestRemainingTime = INT_MAX;
			int selectedProcess = -1;

			for (int i = 0; i < numProcesses; ++i) {
				if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
					if (processes[i].remainingTime < shortestRemainingTime) {
						shortestRemainingTime = processes[i].remainingTime;
						selectedProcess = i;
					}
				}
			}

			if (selectedProcess == -1) {
				currentTime++;
			}
			else {
				if (ganttChart.empty() || ganttChart.back() != processes[selectedProcess].id) {
					ganttChart.push_back(processes[selectedProcess].id);
				}

				processes[selectedProcess].remainingTime--;
				currentTime++;

				if (processes[selectedProcess].remainingTime == 0) {
					processes[selectedProcess].completionTime = currentTime;
					processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
					processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;

					totalTurnaroundTime += processes[selectedProcess].turnaroundTime;
					totalWaitingTime += processes[selectedProcess].waitingTime;

					completedProcesses++;
				}
			}
		}



		// Calculate averages
		avgTurnaroundTime = static_cast<float>(totalTurnaroundTime) / numProcesses;
		avgWaitingTime = static_cast<float>(totalWaitingTime) / numProcesses;
		int totalBurstTime = 0;
		for (int burst : bt) {
			totalBurstTime += burst;
		}
		cpuUtilization = (static_cast<float>(totalBurstTime) / currentTime) * 100;

		
		// Sort processes by their original order

		sort(processes.begin(), processes.end(), sortByOriginalOrder);
		
		// Display process information in tabular format
		stdDetails = "{0, -15}{1, -22}{2, -22}{3, -26}{4, -26}{5, -26}{6, -26}";
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", "                      Shortest Remaining Time First", " ", " ", " "));
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time", "Priority"));
		for (const Process& p : processes) {
			stdDetails = "{0, -25}{1, -30}{2, -30}{3, -33}{4, -33}{5, -33}{6, -33}";

			lbDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime, " "));

		}
		lbDisplay->Items->Add(" ");

		// for allignment
		stdDetails = "{0, -15}{1, -25}{2, -25}{3, -25}{4, -25}{5, -25}{6, -25}";
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", "Average Waiting Time: ", avgWaitingTime, "Average Turn Around time:", avgTurnaroundTime, " "));

		lbDisplay->Items->Add(" ");
		//diplay average
		lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", " ", "CPU Utilization: ", cpuUtilization, " %", " "));
		lblATT->Text = "Average Turn Around Time: " + avgTurnaroundTime.ToString();
		lblAWT->Text = "Average Waiting Time: " + avgTurnaroundTime.ToString();
		lblCPU->Text = "CPU Utilization: " + cpuUtilization.ToString() + " %";
		//space
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(" ");
		lbDisplay->Items->Add(" ");


		//data grid
// Assuming dtDisplay is your DataGridView control
		dgDisplay->Rows->Clear();
		dgDisplay->Columns->Clear();

		// Add columns to the DataGridView
		dgDisplay->Columns->Add("PID", "Process ID");
		dgDisplay->Columns->Add("ArrivalTime", "Arrival Time");
		dgDisplay->Columns->Add("BurstTime", "Burst Time");
		dgDisplay->Columns->Add("CompletionTime", "Completion Time");
		dgDisplay->Columns->Add("TurnaroundTime", "Turn Around Time");
		dgDisplay->Columns->Add("WaitingTime", "Waiting Time");


		// Display process information in DataGridView
		for (const Process& p : processes) {
			dgDisplay->Rows->Add(p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime);
		}
	};
}
private: System::Void rbFCFS_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//hide the textbok and text if the algo is not npp
	this->tbprio->Visible = !this->rbFCFS->Checked;
	if (rbFCFS->Checked) { lblPrio->Text = "";
	lblAlgo->Text = "First Come First Serve";
		this->lbDisplay->Size = System::Drawing::Size(553, 225);
	this->btnCompute->Location = System::Drawing::Point(80, 197);
	}
	else {
		lblPrio->Text = "Priority";
		this->lbDisplay->Size = System::Drawing::Size(630, 225);
	}
}


private: System::Void rbnpp_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (rbnpp->Checked) {
		this->lbDisplay->Size = System::Drawing::Size(630, 225);
		lblAlgo->Text = "Non Preemptive Priority";
		this->btnCompute->Location = System::Drawing::Point(80, 241);
		
	}
	else this->lbDisplay->Size = System::Drawing::Size(553, 225);
}
private: System::Void rbSRTF_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//hide the textbok and text if the algo is not npp
	this->tbprio->Visible = !this->rbSRTF->Checked;
	if (rbSRTF->Checked) {
		lblPrio->Text = "";
		this->lbDisplay->Size = System::Drawing::Size(553, 225);
		this->btnCompute->Location = System::Drawing::Point(80, 197);
		lblAlgo->Text = "Shortest Remaining Time First";
	}

	else {
		lblPrio->Text = "Priority";
		this->lbDisplay->Size = System::Drawing::Size(630, 225);
	}
}


private: System::Void tbprio_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbDisplay_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void lbDisplay_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
	   //clear History
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	lbDisplay->Items->Clear();
}

private: System::Void dgDisplay_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void gbAlgo_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblATT_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}