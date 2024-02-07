
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
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ creditToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ creditsToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ tbBT;
	private: System::Windows::Forms::ListBox^ lbGanttChart;

	private: System::Windows::Forms::Label^ lblRunTime;
	private: System::Windows::Forms::GroupBox^ gbDisplayAvg;
	private: System::Windows::Forms::Label^ lbResults;
	private: System::Windows::Forms::Button^ btnClrtb;









	private:

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->rbFCFS = (gcnew System::Windows::Forms::RadioButton());
			this->rbnpp = (gcnew System::Windows::Forms::RadioButton());
			this->rbSRTF = (gcnew System::Windows::Forms::RadioButton());
			this->gbAlgo = (gcnew System::Windows::Forms::GroupBox());
			this->lbDisplay = (gcnew System::Windows::Forms::ListBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->dgDisplay = (gcnew System::Windows::Forms::DataGridView());
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creditToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tbBT = (gcnew System::Windows::Forms::TextBox());
			this->lbGanttChart = (gcnew System::Windows::Forms::ListBox());
			this->lblRunTime = (gcnew System::Windows::Forms::Label());
			this->gbDisplayAvg = (gcnew System::Windows::Forms::GroupBox());
			this->lbResults = (gcnew System::Windows::Forms::Label());
			this->btnClrtb = (gcnew System::Windows::Forms::Button());
			this->gbAlgo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDisplay))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->gbDisplayAvg->SuspendLayout();
			this->SuspendLayout();
			// 
			// rbFCFS
			// 
			this->rbFCFS->AutoSize = true;
			this->rbFCFS->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbFCFS->Location = System::Drawing::Point(18, 19);
			this->rbFCFS->Name = L"rbFCFS";
			this->rbFCFS->Size = System::Drawing::Size(131, 17);
			this->rbFCFS->TabIndex = 1;
			this->rbFCFS->TabStop = true;
			this->rbFCFS->Text = L"First Come First Serve";
			this->rbFCFS->UseVisualStyleBackColor = true;
			this->rbFCFS->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbFCFS_CheckedChanged);
			// 
			// rbnpp
			// 
			this->rbnpp->AutoSize = true;
			this->rbnpp->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbnpp->Location = System::Drawing::Point(18, 42);
			this->rbnpp->Name = L"rbnpp";
			this->rbnpp->Size = System::Drawing::Size(141, 17);
			this->rbnpp->TabIndex = 2;
			this->rbnpp->TabStop = true;
			this->rbnpp->Text = L"Non Preemprive Priority";
			this->rbnpp->UseVisualStyleBackColor = true;
			this->rbnpp->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbnpp_CheckedChanged);
			// 
			// rbSRTF
			// 
			this->rbSRTF->AutoSize = true;
			this->rbSRTF->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rbSRTF->Location = System::Drawing::Point(18, 65);
			this->rbSRTF->Name = L"rbSRTF";
			this->rbSRTF->Size = System::Drawing::Size(172, 17);
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
			this->gbAlgo->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbAlgo->Location = System::Drawing::Point(28, 382);
			this->gbAlgo->Name = L"gbAlgo";
			this->gbAlgo->Size = System::Drawing::Size(198, 90);
			this->gbAlgo->TabIndex = 4;
			this->gbAlgo->TabStop = false;
			this->gbAlgo->Text = L"Algorithm";
			this->gbAlgo->Enter += gcnew System::EventHandler(this, &MyForm::gbAlgo_Enter);
			// 
			// lbDisplay
			// 
			this->lbDisplay->BackColor = System::Drawing::Color::White;
			this->lbDisplay->FormattingEnabled = true;
			this->lbDisplay->Location = System::Drawing::Point(239, 347);
			this->lbDisplay->Name = L"lbDisplay";
			this->lbDisplay->Size = System::Drawing::Size(627, 199);
			this->lbDisplay->TabIndex = 6;
			this->lbDisplay->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::lbDisplay_SelectedIndexChanged_1);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btnClear->Location = System::Drawing::Point(75, 509);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(89, 36);
			this->btnClear->TabIndex = 7;
			this->btnClear->Text = L"Clear History";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			// 
			// dgDisplay
			// 
			this->dgDisplay->AllowDrop = true;
			this->dgDisplay->AllowUserToAddRows = false;
			this->dgDisplay->AllowUserToDeleteRows = false;
			this->dgDisplay->BackgroundColor = System::Drawing::Color::White;
			this->dgDisplay->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::ActiveBorder;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgDisplay->DefaultCellStyle = dataGridViewCellStyle1;
			this->dgDisplay->Location = System::Drawing::Point(239, 75);
			this->dgDisplay->MultiSelect = false;
			this->dgDisplay->Name = L"dgDisplay";
			this->dgDisplay->ReadOnly = true;
			this->dgDisplay->RowHeadersWidth = 51;
			this->dgDisplay->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dgDisplay->Size = System::Drawing::Size(626, 230);
			this->dgDisplay->TabIndex = 8;
			this->dgDisplay->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dgDisplay_CellContentClick);
			// 
			// tbAT
			// 
			this->tbAT->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(214)));
			this->tbAT->Location = System::Drawing::Point(28, 152);
			this->tbAT->Name = L"tbAT";
			this->tbAT->Size = System::Drawing::Size(188, 20);
			this->tbAT->TabIndex = 0;
			this->tbAT->TextChanged += gcnew System::EventHandler(this, &MyForm::tbAT_TextChanged);
			// 
			// btnCompute
			// 
			this->btnCompute->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btnCompute->Location = System::Drawing::Point(127, 288);
			this->btnCompute->Name = L"btnCompute";
			this->btnCompute->Size = System::Drawing::Size(89, 36);
			this->btnCompute->TabIndex = 2;
			this->btnCompute->Text = L"Compute";
			this->btnCompute->UseVisualStyleBackColor = false;
			this->btnCompute->Click += gcnew System::EventHandler(this, &MyForm::btnCompute_Click);
			// 
			// lblAT
			// 
			this->lblAT->AutoSize = true;
			this->lblAT->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAT->Location = System::Drawing::Point(25, 131);
			this->lblAT->Name = L"lblAT";
			this->lblAT->Size = System::Drawing::Size(66, 13);
			this->lblAT->TabIndex = 3;
			this->lblAT->Text = L"Arrival Time";
			this->lblAT->Click += gcnew System::EventHandler(this, &MyForm::lblAT_Click);
			// 
			// lblBT
			// 
			this->lblBT->AutoSize = true;
			this->lblBT->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBT->Location = System::Drawing::Point(25, 177);
			this->lblBT->Name = L"lblBT";
			this->lblBT->Size = System::Drawing::Size(59, 13);
			this->lblBT->TabIndex = 4;
			this->lblBT->Text = L"Burst Time";
			this->lblBT->Click += gcnew System::EventHandler(this, &MyForm::lblBT_Click);
			// 
			// tbprio
			// 
			this->tbprio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(214)));
			this->tbprio->Location = System::Drawing::Point(28, 246);
			this->tbprio->Name = L"tbprio";
			this->tbprio->Size = System::Drawing::Size(188, 20);
			this->tbprio->TabIndex = 5;
			this->tbprio->TextChanged += gcnew System::EventHandler(this, &MyForm::tbprio_TextChanged);
			// 
			// lblPrio
			// 
			this->lblPrio->AutoSize = true;
			this->lblPrio->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPrio->Location = System::Drawing::Point(25, 226);
			this->lblPrio->Name = L"lblPrio";
			this->lblPrio->Size = System::Drawing::Size(42, 13);
			this->lblPrio->TabIndex = 6;
			this->lblPrio->Text = L"Priority";
			this->lblPrio->Click += gcnew System::EventHandler(this, &MyForm::lblPrio_Click);
			// 
			// lblAlgo
			// 
			this->lblAlgo->AutoSize = true;
			this->lblAlgo->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAlgo->Location = System::Drawing::Point(233, 36);
			this->lblAlgo->Name = L"lblAlgo";
			this->lblAlgo->Size = System::Drawing::Size(207, 32);
			this->lblAlgo->TabIndex = 9;
			this->lblAlgo->Text = L"Welcome User!";
			this->lblAlgo->UseMnemonic = false;
			this->lblAlgo->Click += gcnew System::EventHandler(this, &MyForm::lblAlgo_Click);
			// 
			// lblHistory
			// 
			this->lblHistory->AutoSize = true;
			this->lblHistory->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20.25F));
			this->lblHistory->Location = System::Drawing::Point(233, 308);
			this->lblHistory->Name = L"lblHistory";
			this->lblHistory->Size = System::Drawing::Size(111, 32);
			this->lblHistory->TabIndex = 10;
			this->lblHistory->Text = L"History";
			// 
			// lblATT
			// 
			this->lblATT->AutoSize = true;
			this->lblATT->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblATT->Location = System::Drawing::Point(5, 18);
			this->lblATT->Name = L"lblATT";
			this->lblATT->Size = System::Drawing::Size(141, 13);
			this->lblATT->TabIndex = 11;
			this->lblATT->Text = L"Average Turn Around Time: ";
			this->lblATT->Click += gcnew System::EventHandler(this, &MyForm::lblATT_Click);
			// 
			// lblAWT
			// 
			this->lblAWT->AutoSize = true;
			this->lblAWT->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAWT->Location = System::Drawing::Point(5, 43);
			this->lblAWT->Name = L"lblAWT";
			this->lblAWT->Size = System::Drawing::Size(120, 13);
			this->lblAWT->TabIndex = 12;
			this->lblAWT->Text = L"Average Waiting Time: ";
			// 
			// lblCPU
			// 
			this->lblCPU->AutoSize = true;
			this->lblCPU->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCPU->Location = System::Drawing::Point(5, 68);
			this->lblCPU->Name = L"lblCPU";
			this->lblCPU->Size = System::Drawing::Size(87, 13);
			this->lblCPU->TabIndex = 13;
			this->lblCPU->Text = L"CPU Utilization: ";
			this->lblCPU->Click += gcnew System::EventHandler(this, &MyForm::lblCPU_Click);
			// 
			// lblDisp
			// 
			this->lblDisp->AutoSize = true;
			this->lblDisp->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDisp->Location = System::Drawing::Point(24, 75);
			this->lblDisp->Name = L"lblDisp";
			this->lblDisp->Size = System::Drawing::Size(176, 40);
			this->lblDisp->TabIndex = 14;
			this->lblDisp->Text = L"Process Scheduling \r\nAlgorithm:";
			this->lblDisp->Click += gcnew System::EventHandler(this, &MyForm::lblDisp_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1115, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->creditToolStripMenuItem,
					this->creditsToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// creditToolStripMenuItem
			// 
			this->creditToolStripMenuItem->Name = L"creditToolStripMenuItem";
			this->creditToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->creditToolStripMenuItem->Text = L"User Manual";
			this->creditToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::creditToolStripMenuItem_Click);
			// 
			// creditsToolStripMenuItem
			// 
			this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
			this->creditsToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->creditsToolStripMenuItem->Text = L"Credits";
			this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::creditsToolStripMenuItem_Click);
			// 
			// tbBT
			// 
			this->tbBT->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(214)));
			this->tbBT->Location = System::Drawing::Point(28, 197);
			this->tbBT->Name = L"tbBT";
			this->tbBT->Size = System::Drawing::Size(188, 20);
			this->tbBT->TabIndex = 1;
			this->tbBT->TextChanged += gcnew System::EventHandler(this, &MyForm::tbBT_TextChanged);
			// 
			// lbGanttChart
			// 
			this->lbGanttChart->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->lbGanttChart->FormattingEnabled = true;
			this->lbGanttChart->Location = System::Drawing::Point(888, 347);
			this->lbGanttChart->Name = L"lbGanttChart";
			this->lbGanttChart->Size = System::Drawing::Size(191, 199);
			this->lbGanttChart->TabIndex = 16;
			// 
			// lblRunTime
			// 
			this->lblRunTime->AutoSize = true;
			this->lblRunTime->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20));
			this->lblRunTime->Location = System::Drawing::Point(883, 309);
			this->lblRunTime->Name = L"lblRunTime";
			this->lblRunTime->Size = System::Drawing::Size(137, 32);
			this->lblRunTime->TabIndex = 17;
			this->lblRunTime->Text = L"Run time";
			this->lblRunTime->Click += gcnew System::EventHandler(this, &MyForm::lblRunTime_Click);
			// 
			// gbDisplayAvg
			// 
			this->gbDisplayAvg->Controls->Add(this->lblATT);
			this->gbDisplayAvg->Controls->Add(this->lblCPU);
			this->gbDisplayAvg->Controls->Add(this->lblAWT);
			this->gbDisplayAvg->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20));
			this->gbDisplayAvg->Location = System::Drawing::Point(888, 143);
			this->gbDisplayAvg->Margin = System::Windows::Forms::Padding(2);
			this->gbDisplayAvg->Name = L"gbDisplayAvg";
			this->gbDisplayAvg->Padding = System::Windows::Forms::Padding(2);
			this->gbDisplayAvg->Size = System::Drawing::Size(191, 96);
			this->gbDisplayAvg->TabIndex = 0;
			this->gbDisplayAvg->TabStop = false;
			this->gbDisplayAvg->Enter += gcnew System::EventHandler(this, &MyForm::gbDisplayAvg_Enter);
			// 
			// lbResults
			// 
			this->lbResults->AutoSize = true;
			this->lbResults->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 20));
			this->lbResults->Location = System::Drawing::Point(883, 116);
			this->lbResults->Name = L"lbResults";
			this->lbResults->Size = System::Drawing::Size(110, 32);
			this->lbResults->TabIndex = 18;
			this->lbResults->Text = L"Results";
			// 
			// btnClrtb
			// 
			this->btnClrtb->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(187)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
				static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->btnClrtb->Location = System::Drawing::Point(32, 288);
			this->btnClrtb->Name = L"btnClrtb";
			this->btnClrtb->Size = System::Drawing::Size(89, 36);
			this->btnClrtb->TabIndex = 19;
			this->btnClrtb->Text = L"Clear";
			this->btnClrtb->UseVisualStyleBackColor = false;
			this->btnClrtb->Click += gcnew System::EventHandler(this, &MyForm::btnClrtb_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(221)), static_cast<System::Int32>(static_cast<System::Byte>(226)),
				static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->ClientSize = System::Drawing::Size(1115, 568);
			this->Controls->Add(this->btnClrtb);
			this->Controls->Add(this->lbResults);
			this->Controls->Add(this->gbDisplayAvg);
			this->Controls->Add(this->lblRunTime);
			this->Controls->Add(this->lbGanttChart);
			this->Controls->Add(this->lblDisp);
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
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"WMI Process Scheduling";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->gbAlgo->ResumeLayout(false);
			this->gbAlgo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgDisplay))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->gbDisplayAvg->ResumeLayout(false);
			this->gbDisplayAvg->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}



#pragma endregion

		String^ stdDetails;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		rbFCFS->Checked = true;
		dgDisplay->ReadOnly = true;
	}


	private: System::Void btnCompute_Click(System::Object^ sender, System::EventArgs^ e) {


		// Input handling for arrival times, burst time, priority
		if (this->tbAT->Text == "") {
			MessageBox::Show("Arrival time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (this->tbBT->Text == "") {
			MessageBox::Show("Burst time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (rbFCFS->Checked) {
			// Declare variables to store process information and various metrics
			int numProcesses;
			vector<Process> processes;
			float avgTurnaroundTime, avgWaitingTime, avgResponseTime, cpuUtilization, throughput;
			int totalTurnaroundTime = 0, totalWaitingTime = 0, totalResponseTime = 0, totalIdleTime = 0;
			String^ tempBurstTime, ^ tempArrivalTime = "";

			// Input handling for arrival times
			tempArrivalTime = tbAT->Text;

			// Input handling for arrival times
			if (tempArrivalTime == "") {
				MessageBox::Show("Arrival time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
			// Input handling for burst times
			if (tempBurstTime == "") {
				MessageBox::Show("Burst time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
				if (at[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				if (bt[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
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

			// Display process information of cpu runtime sequentially in lbgc ListBox
			//delete first the history
			lbGanttChart->Items->Clear();
			for (const Process& p : processes) {
				// Display start time
				lbGanttChart->Items->Add(String::Format("P{0} started at {1} milliseconds.", p.id, p.startTime));

				// Display end time
				lbGanttChart->Items->Add(String::Format("P{0} ended at {1} milliseconds.", p.id, p.completionTime));

				// Add a separator for clarity
				lbGanttChart->Items->Add(" ");
			}

			// Display process information in tabular format
			stdDetails = "{0, -15}{1, -22}{2, -22}{3, -26}{4, -26}{5, -26}";
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", "                      First Come First Serve", " ", " ", " "));
			lbDisplay->Items->Add(" ");
			lbDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time"));

			for (const Process& p : processes) {
				stdDetails = "{0, -25}{1, -30}{2, -30}{3, -33}{4, -33}{5, -33}";
				lbDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime));

			}
			lbDisplay->Items->Add(" ");

			// for allignment
			stdDetails = "{0, -15}{1, -25}{2, -25}{3, -25}{4, -25}{5, -25}{6, -25}";
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", "Average Waiting Time: ", avgWaitingTime, "Average Turn Around time:", avgTurnaroundTime, " "));

			lbDisplay->Items->Add(" ");

			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", " ", "CPU Utilization: ", cpuUtilization + " %", "", " "));

			//diplay average
			lblATT->Text = "Average Turn Around Time: " + avgTurnaroundTime.ToString("0.00");
			lblAWT->Text = "Average Waiting Time: " + avgWaitingTime.ToString("0.00");
			lblCPU->Text = "CPU Utilization: " + cpuUtilization.ToString("0.00") + " %";

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
			String^ tempBurstTime, ^ tempArrivalTime, ^ tempPriority;

			tempArrivalTime = tbAT->Text;
			// Input handling for arrival times
			if (tempArrivalTime == "") {
				MessageBox::Show("Arrival time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
			// Input handling for burst times
			if (tempBurstTime == "") {
				MessageBox::Show("Burst time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
			if (tempPriority == "") {
				MessageBox::Show("Priority cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
				if (at[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				if (bt[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				if (priority[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
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

			// Display process information of cpu runtime sequentially in lbgc ListBox
			//delete first the history
			lbGanttChart->Items->Clear();
			for (const Process& p : processes) {
				// Display start time
				lbGanttChart->Items->Add(String::Format("P{0} started at {1} milliseconds.", p.id, p.startTime));

				// Display end time
				lbGanttChart->Items->Add(String::Format("P{0} ended at {1} milliseconds.", p.id, p.completionTime));

				// Add a separator for clarity
				lbGanttChart->Items->Add(" ");
			}

			// Display process information in tabular format
			stdDetails = "{0, -15}{1, -22}{2, -22}{3, -26}{4, -26}{5, -26}{6, -26}";
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", "                      Non Preemptive Priority", " ", " ", " "));
			lbDisplay->Items->Add(" ");
			lbDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time", "Priority"));

			for (const Process& p : processes) {
				stdDetails = "{0, -25}{1, -30}{2, -30}{3, -33}{4, -33}{5, -33}{6, -33}";
				lbDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime, +p.priority));
			}

			lbDisplay->Items->Add(" ");

			// for allignment
			stdDetails = "{0, -15}{1, -25}{2, -25}{3, -25}{4, -25}{5, -25}{6, -25}";
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", "Average Waiting Time: ", avgWaitingTime, "Average Turn Around time:", avgTurnaroundTime, " "));

			lbDisplay->Items->Add(" ");

			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", " ", "CPU Utilization: ", cpuUtilization + " %", " ", " "));

			//diplay average
			lblATT->Text = "Average Turn Around Time: " + avgTurnaroundTime.ToString("0.00");
			lblAWT->Text = "Average Waiting Time: " + avgWaitingTime.ToString("0.00");
			lblCPU->Text = "CPU Utilization: " + cpuUtilization.ToString("0.00") + " %";

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
			String^ tempBursttime, ^ tempArrivalTime;

			// Input handling for arrival times
			tempArrivalTime = tbAT->Text;
			if (tempArrivalTime == "") {
				MessageBox::Show("Arrival time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
			if (tempBursttime == "") {
				MessageBox::Show("Burst time cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

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
				if (at[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				if (bt[i] < 0) {
					MessageBox::Show("Invalid Input", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
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

			// Display process information of cpu runtime sequentially in lbgc ListBox
			//delete first the history
			lbGanttChart->Items->Clear();
			for (const Process& p : processes) {
				// Display start time
				lbGanttChart->Items->Add(String::Format("P{0} started at {1} milliseconds.", p.id, p.startTime));

				// Display end time
				lbGanttChart->Items->Add(String::Format("P{0} ended at {1} milliseconds.", p.id, p.completionTime));

				// Add a separator for clarity
				lbGanttChart->Items->Add(" ");
			}


			// Display process information in tabular format
			stdDetails = "{0, -15}{1, -22}{2, -22}{3, -26}{4, -26}{5, -26}";
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", "                      Shortest Remaining Time First", " ", " "));
			lbDisplay->Items->Add(" ");
			lbDisplay->Items->Add(String::Format(stdDetails, "PID", "Arrival Time", "Burst Time", "Completion Time", "Turn Around Time", "Waiting Time"));
			for (const Process& p : processes) {
				stdDetails = "{0, -25}{1, -30}{2, -30}{3, -33}{4, -33}{5, -33}";

				lbDisplay->Items->Add(String::Format(stdDetails, p.id, p.arrivalTime, p.burstTime, p.completionTime, p.turnaroundTime, p.waitingTime, " "));

			}
			lbDisplay->Items->Add(" ");

			// for allignment
			stdDetails = "{0, -15}{1, -25}{2, -25}{3, -25}{4, -25}{5, -25}{6, -25}";
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", "Average Waiting Time: ", avgWaitingTime, "Average Turn Around time:", avgTurnaroundTime, " "));

			lbDisplay->Items->Add(" ");
			//diplay average
			lbDisplay->Items->Add(String::Format(stdDetails, " ", " ", " ", " ", "CPU Utilization: ", cpuUtilization  + " %", " ", " "));
			lblATT->Text = "Average Turn Around Time: " + avgTurnaroundTime.ToString("0.00");
			lblAWT->Text = "Average Waiting Time: " + avgWaitingTime.ToString("0.00");
			lblCPU->Text = "CPU Utilization: " + cpuUtilization.ToString("0.00") + " %";
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
		if (rbFCFS->Checked) {
			lblPrio->Text = "";
			lblAlgo->Text = "First Come First Serve";
			this->btnCompute->Location = System::Drawing::Point(127, 230);
			this->btnClrtb->Location = System::Drawing::Point(32, 230);
			

		}
		else {
			lblPrio->Text = "Priority";
		}
	}


	private: System::Void rbnpp_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (rbnpp->Checked) {
			lblAlgo->Text = "Non Preemptive Priority";
			this->btnCompute->Location = System::Drawing::Point(127, 288);
			this->btnClrtb->Location = System::Drawing::Point(32, 288);
			
		}
	}
	private: System::Void rbSRTF_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		//hide the textbok and text if the algo is not npp
		this->tbprio->Visible = !this->rbSRTF->Checked;
		if (rbSRTF->Checked) {
			lblPrio->Text = "";
			lblAlgo->Text = "Shortest Remaining Time First";
			this->btnCompute->Location = System::Drawing::Point(127, 230);
			this->btnClrtb->Location = System::Drawing::Point(32, 230);
		}

		else {
			lblPrio->Text = "Priority";
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
	private: System::Void lblAlgo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblDisp_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblCPU_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void creditToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//
		// For User Manual
		//
		MessageBox::Show("STEP 1: Choose your preferred Process Scheduling Algorithm.\n" 
			"\nSTEP 2: Input the arrival time and burst time (as well as the priority if the Non-Preemptive Priority Algorithm is chosen) separated by spaces/commas.\n" 
			"\nSTEP 3: After inputting, click 'Compute'. \n"
			"\nSTEP 4: The program will then compute the turnaround time, waiting time, and their average, as well as the CPU utilization. The result will appear in a table format and will also be stored in the History box. \n"
			"\nSTEP 5: To clear the result history, click 'Clear History' under the scheduling algorithm choices."
			"\nNote: The history of the Algorithms' results are only kept during the runtime of the program. \n"
			"\n\nTERMS USED IN THE PROGRAM: "
			"\nArrival Time (AT) – Time at which the process arrives in the ready queue. "
			"\nBurst Time (BT) – Time required by a process for CPU execution."
			"\nPriority - The numerical value assigned to a process, indicating its relative importance or urgency in being executed. Higher priority tasks get done first."
			"\nTurn Around Time (TaT) – Time difference between completion time and arrival time. "
			"\nWaiting Time (WT) – Time difference between TaT and BT." 
			"\nCPU Utilization - Percentage of how much the computer processor is being used.", "User Manual", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void lblPrio_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tbBT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblBT_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tbAT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void lblAT_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void creditsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//
		// For Credits (Authors)
		//
		MessageBox::Show("Created by BSIT 2-1 A.Y. 2023\n\nLead Programmer:\nJan Leo B. Egamen\n\nBackend Developers: \nEmma Marie S. Hechanova \nMa. Ellyza R. Teñiero \n\nFrontend Developer: \nAlec Godwin C. Almirañez \n\nTechnical Writer: \nVince Gabriel G. Razon ", "Authors", MessageBoxButtons::OK, MessageBoxIcon::Information
		);
	}

	private: System::Void lblRunTime_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void gbDisplayAvg_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnClrtb_Click(System::Object^ sender, System::EventArgs^ e) {

	this->tbAT->Text = "";
	this->tbBT->Text = "";
	this->tbprio->Text = "";
	// button clears data grid and results group
	dgDisplay->Rows->Clear();
	dgDisplay->Columns->Clear();
	lbGanttChart->Items->Clear();
	lblATT->Text = "";
	lblAWT->Text = "";
	lblCPU->Text = "";

}
};
}